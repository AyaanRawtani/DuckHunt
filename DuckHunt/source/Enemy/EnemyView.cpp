#include "Enemy/EnemyView.h"
#include "Enemy/EnemyController.h"
#include "Global/ServiceLocator.h"
#include "Graphics/GraphicService.h"
#include "Enemy/EnemyConfig.h"
#include "header/Enemy/EnemyAnimationConfigData.h"



namespace Enemy
{

	using namespace Global;
	using namespace UI::UIElement;

	EnemyView::EnemyView()
	{
		createUIElements();
	}

	EnemyView::~EnemyView()
	{
		destroy();
	}

	void EnemyView::initialize(EnemyController* controller)
	{
		enemy_controller = controller;
		//game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		currentFrame = 0;
		initializeImage();
	}


	void EnemyView::createUIElements()
	{
		enemy_image = new ImageView();
	}

	void EnemyView::initializeImage()
	{
		enemy_image->initialize(getEnemyTexturePath(), enemy_sprite_height, enemy_sprite_width, enemy_controller->getEnemyPosition());
		enemy_image->setTextureRect(sf::IntRect(0, 0, enemyAnimationConfig.tileWidth, enemyAnimationConfig.tileHeight));
	
	}

	sf::String EnemyView::getEnemyTexturePath()
	{
		switch (enemy_controller->getEnemyType())
		{
		case::Enemy::EnemyKind::GREENBIRD:
			return green_texture_path;


		case::Enemy::EnemyKind::REDBIRD:
			return red_texture_path;

		
		}


	}

	void EnemyView::update()
	{
		elapsedTime += Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
		enemy_image->setPosition(enemy_controller->getEnemyPosition());
		if (enemy_controller->getEnemyState() == EnemyState::FLYING)
		{
			updateAnimation(enemyAnimationConfig);
		}

		else
		{
			enemy_image->setRotation(0);
			if (!deadAnimationFinished)
			{
				showDeadAnimation(enemyDeadAnimationConfig);
			}
			else
			{
				updateAnimation(enemyRotatingAnimationConfig);
			}


		}
	}

	void EnemyView::updateAnimation(EnemyAnimationConfig animationConfig)
	{
		if (elapsedTime >= animationConfig.frameDuration)
		{
			if (currentFrame + 1 >= animationConfig.numberOfAnimationFrame)
			{
				currentFrame = 0;
			}

			else
			{
				currentFrame = (currentFrame + 1) % animationConfig.numberOfAnimationFrame;
			}

			enemy_image->setTextureRect(sf::IntRect(
				animationConfig.tileStart + (currentFrame * animationConfig.tileWidth),
				0,
				animationConfig.tileWidth,
				animationConfig.tileHeight));
			elapsedTime = 0.f;
			enemy_image->update();
		}
		
	}

	void EnemyView::showDeadAnimation(EnemyAnimationConfig animationConfig)
	{
		enemy_image->setTextureRect(sf::IntRect(
			animationConfig.tileStart,
			0,
			animationConfig.tileWidth,
			animationConfig.tileHeight
		));
		if (elapsedTime >= animationConfig.frameDuration)
		{
			currentFrame = 0;
			elapsedTime = 0.f;
			deadAnimationFinished = true;
		
		}

		enemy_image->update();
	}

	

	void EnemyView::render()
	{
		enemy_image->render();
	}

	const float EnemyView::getSpriteWidth()
	{
		return enemy_sprite_width;
	}

	const float EnemyView::getSpriteHeight()
	{
		return enemy_sprite_height;
	}

	const sf::Sprite EnemyView::getEnemySprite()
	{
		return enemy_image->getSprite();
	}

	void EnemyView::setScale(int flip)
	{
		enemy_image->setScale(enemy_sprite_width, enemy_sprite_height,  flip * enemyAnimationConfig.tileWidth, enemyAnimationConfig.tileHeight);
	}

	
	void EnemyView::destroy()
	{
		delete(enemy_image);
		
	}

}