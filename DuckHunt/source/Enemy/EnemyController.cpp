#include "Enemy/EnemyController.h"
#include "Enemy/EnemyModel.h"
#include "Enemy/EnemyView.h"
#include "Enemy/EnemyConfig.h"
#include "Global/ServiceLocator.h"
#include "Time/TimeService.h"
#include <iostream>



namespace Enemy
{
	using namespace Global;

	EnemyController::EnemyController(EnemyKind type)
	{
		enemy_view = new EnemyView();
		enemy_model = new EnemyModel(type);
	}

	EnemyController::~EnemyController()
	{
		delete(enemy_view);
		delete(enemy_model);
	}



	 void EnemyController::initialize()
	{
		enemy_model->initialize();
		enemy_view->initialize(this);

		
	}

	void EnemyController::update()
	{
		moveAndRebound();
		enemy_view->update();
	}

	void EnemyController::moveAndRebound()
	{
		
		current_position = enemy_model->getEnemyPosition();
		current_velocity = enemy_model->getVelocity();

		calculateNewPosition();
		handleHorizontalRebound();
		handleVerticalRebound();
		updatePositionAndVelocity();
	}

	void EnemyController::calculateNewPosition()
	{
		float deltaTime = ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		current_position += current_velocity * deltaTime;
	}

	void EnemyController::handleHorizontalRebound()
	{
		if (current_position.x <= leftBound)
		{
			current_position.x = leftBound;
			current_velocity.x = -current_velocity.x;
		}
		else if (current_position.x + enemy_view->getSpriteWidth() >= rightBound)
		{
			current_position.x = rightBound - enemy_view->getSpriteWidth();
			current_velocity.x = -current_velocity.x;
		}
	}

	void EnemyController::handleVerticalRebound()
	{
		if (current_position.y <= topBound)
		{
			current_position.y = topBound;
			current_velocity.y = -current_velocity.y;
		}
		else if (current_position.y + enemy_view->getSpriteHeight() >= bottomBound)
		{
			current_position.y = bottomBound - enemy_view->getSpriteHeight();
			current_velocity.y = -current_velocity.y;
		}
	}

	void EnemyController::updatePositionAndVelocity()
	{
		enemy_model->setEnemyPosition(current_position);
		enemy_model->setVelocity(current_velocity);
	}


	//void EnemyController::moveAndRebound()
	//{
	//	sf::Vector2f current_position = enemy_model->getEnemyPosition();
	//	sf::Vector2f current_velocity = enemy_model->getVelocity();

	//	float deltaTime = ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

	//	current_position += current_velocity * deltaTime;

	//	if (current_position.x <= leftBound)
	//	{
	//		current_position.x = leftBound;
	//		current_velocity.x = -current_velocity.x;

	//		//std::cout << "Hit right bound. New velocity: " << current_velocity.x << std::endl;
	//	
	//	}

	//	if (current_position.x + enemy_view-> getSpriteWidth() >= rightBound)    // + 60 because sprite width is 60.f and 0,0 is top left of sprite so right edge of sprite is 0+60 
	//	{
	//		current_position.x = rightBound - enemy_view->getSpriteWidth();
	//		current_velocity.x = -current_velocity.x;

	//		//std::cout << "Hit right bound. New velocity: " << current_velocity.x << std::endl;
	//	}

	//	if (current_position.y <= topBound)
	//	{
	//		current_position.y = topBound;
	//		current_velocity.y = -current_velocity.y;

	//		//std::cout << "Hit right bound. New velocity: " << current_velocity.y << std::endl;
	//	}

	//	if (current_position.y + enemy_view->getSpriteHeight() >= bottomBound)
	//	{
	//		current_position.y = bottomBound - enemy_view->getSpriteHeight();         // need to create getSpriteSize in enemy_view
	//		current_velocity.y = -current_velocity.y;

	//		//std::cout << "Hit right bound. New velocity: " << current_velocity.y << std::endl;
	//	}

	//	
	//	enemy_model->setEnemyPosition(current_position);
	//	enemy_model->setVelocity(current_velocity);

	//	
	//}
	
	void EnemyController::render()
	{
		enemy_view->render();
	}


	sf::Vector2f EnemyController::getEnemyPosition()
	{
		return enemy_model->getEnemyPosition();
	}

	sf::Vector2f EnemyController::getEnemyVelocity()
	{
		return enemy_model->getVelocity();
	}

	sf::Vector2f EnemyController::setEnemyVelocity(sf::Vector2f velocity)
	{
		return enemy_model->getRandomVelocity();
	}

	EnemyKind EnemyController::getEnemyType()
	{
		return enemy_model->getEnemyType();
	}

	EnemyState EnemyController::getEnemyState()
	{
		return enemy_model->getEnemyState();
	}

	bool EnemyController::checkCollision(const sf::Vector2i& mousePos)
	{
		sf::Sprite collision_sprite = enemy_view->getEnemySprite();
		sf::FloatRect enemyBounds = collision_sprite.getGlobalBounds();

		return enemyBounds.contains(static_cast<sf::Vector2f> (mousePos));
	
	}

	void EnemyController::destroy()
	{
		//printf("Enemy destoryed");
		ServiceLocator::getInstance()->getEnemyService()->destroyEnemy(this);
	}
	
	
}