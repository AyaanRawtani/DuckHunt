#include "Player/PlayerController.h"
#include "Global/ServiceLocator.h"
#include "Event/EventService.h"
#include <iostream>
namespace Player
{
	using namespace Global;
	using namespace Event;

	PlayerController::PlayerController()
	{
	}
	PlayerController::~PlayerController()
	{
	}
	void PlayerController::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		Enemy::EnemyService* enemy_service = ServiceLocator::getInstance()->getEnemyService();
		enemies_list = enemy_service->getEnemyVector();
	}

	bool PlayerController::pressed_left_mb()
	{
		return ServiceLocator::getInstance()->getEventService()->pressedLeftMouseButton(); 
	}

	bool PlayerController::pressed_right_mb()
	{
		return ServiceLocator::getInstance()->getEventService()->pressedRightMouseButton();
	}
	void PlayerController::update()
	{
		
		if (pressed_left_mb()) 
		{
			handleLeftMouseClick();
		}

		if (pressed_right_mb())
		{
			handleRightMouseClick();
		}
	}

	void PlayerController::handleLeftMouseClick()                             // left click is regular bullet point n click 
	{
		sf::Vector2i mousePosition = sf::Mouse::getPosition(*game_window);
		std::vector<EnemyController*> enemies_list = ServiceLocator::getInstance()->getEnemyService()->getEnemyVector();

		for (EnemyController* enemy_controller : enemies_list)
		{
			if (enemy_controller->checkCollision(mousePosition) && pressed_left_mb())
			{
				std::cout << "Enemy Destroyed" << std::endl;
				enemy_controller->destroy();
			}
				
		}
	}

	void PlayerController::handleRightMouseClick()                                //right click is AOE bullet
	{
		sf::Vector2i mousePosition = sf::Mouse::getPosition(*game_window);
		float radius = 100.f; 
		float radius_squared = radius * radius; 

		
		std::vector<EnemyController*> enemies_list = ServiceLocator::getInstance()->getEnemyService()->getEnemyVector();
		for (EnemyController* enemy_controller : enemies_list)
		{
			sf::Vector2f enemy_position = enemy_controller->getEnemyPosition();
			float dx = enemy_position.x - mousePosition.x;                                  //calculates distance between enemy x pos and mouse pos .x 
			float dy = enemy_position.y - mousePosition.y;									//calculates distance between enemy y pos and mouse pos .y 

			
			float distance_squared = dx * dx + dy * dy;                                     //getting squared distance to see if enemy is wihtin attack radius 

			
			if (distance_squared <= radius_squared && pressed_right_mb())				 // if the dist between enemy and mouse pos is less than the AOE bullet radius we destroy the enemy 			
			{
				std::cout << "Enemy Destroyed by AOE" << std::endl;
				enemy_controller->destroy();
			}
		}
	}
}