#include "Player/PlayerController.h"
#include "Global/ServiceLocator.h"
#include "Event/EventService.h"
#include "Player/PlayerModel.h"
#include <iostream>
using namespace std;
namespace Player
{
	using namespace Global;
	using namespace Event;

	PlayerController::PlayerController()
	{
		player_model = new PlayerModel();
	}
	PlayerController::~PlayerController()
	{
		delete(player_model);
	}
	void PlayerController::initialize()
	{
		player_model->initialize();
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		
	}

	void PlayerController::reset()
	{
		player_model->reset();
	}

	void PlayerController::resetAmmo()
	{
		player_model->resetAmmo();
	}



	void PlayerController::loseLife()
	{
		player_model->setPlayerLives(player_model->getPlayerLives() - 1);
		if (player_model->getPlayerLives() <= 0)
		{
			Global::ServiceLocator::getInstance()->reset();
		}
	
		
	}

	int PlayerController::getLives()
	{
		return player_model->getPlayerLives();
	}

	bool PlayerController::pressed_left_mb()
	{
		return ServiceLocator::getInstance()->getEventService()->pressedLeftMouseButton(); 
		//reduceAmmo();
	}

	bool PlayerController::pressed_right_mb()
	{
		return ServiceLocator::getInstance()->getEventService()->pressedRightMouseButton();
		//reduceAOEAmmo();
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
		reduceAmmo();
		if (player_model->getRegularAmmo() >= 0)
		{


			sf::Vector2i mousePosition = sf::Mouse::getPosition(*game_window);
			std::vector<EnemyController*> enemies_list = ServiceLocator::getInstance()->getEnemyService()->getEnemyVector();

			for (EnemyController* enemy_controller : enemies_list)
			{
				if (enemy_controller->checkCollision(mousePosition) && pressed_left_mb())
				{
					std::cout << "Enemy Destroyed" << std::endl;
					enemy_controller->destroy();
					//reduceAmmo();
				}

			}
		}

		else
		{
			cout << "Out of Regular ammo" << endl;
			loseLife();
		}
		
	}

	void PlayerController::handleRightMouseClick()                                //right click is AOE bullet
	{
		reduceAOEAmmo();
		if (player_model->getAoeAmmo() >= 0)
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
					//reduceAOEAmmo();
				}
			}
		}

		else
		{
			cout << "Out of AOE ammo " << endl;
			loseLife();
		}
	}

	int PlayerController::getScore()
	{
		return player_model->getPlayerScore();;
	}
	void PlayerController::increaseScore(int increaseAmount)
	{
		player_model->setPlayerScore(getScore() + increaseAmount);
	}

	void PlayerController::reduceAmmo()
	{
		player_model->setRegularAmmo(player_model->getRegularAmmo() - 1);
		if (player_model->getRegularAmmo() < 0)
		{
			cout << "NO regular ammo left " << endl;
		}
	}

	void PlayerController::reduceAOEAmmo()
	{
		player_model->setAoeAmmo(player_model->getAoeAmmo() - 1);
		if (player_model->getAoeAmmo() < 0)
		{
			cout << "NO AOE ammo left " << endl;
		}
	}


	int PlayerController::getRegularAmmo() const
	{
		return player_model->getRegularAmmo();
	}

	void PlayerController::setRegularAmmo(int ammo)
	{
		player_model->setRegularAmmo(ammo);
	}

	int PlayerController::getAoeAmmo() const
	{
		return  player_model->getAoeAmmo();
	}

	void PlayerController::setAoeAmmo(int ammo)
	{
		player_model->setAoeAmmo(ammo);
	}
	void PlayerController::increaseAmmo()
	{
		//player_model->setRegularAmmo(Global::ServiceLocator::getInstance()->getGameplayService()->getNoofEnemiesToSpawn());
		int newAmmo = Global::ServiceLocator::getInstance()->getGameplayService()->getNoofEnemiesToSpawn();
		std::cout << "Increasing ammo to match enemies to spawn: " << newAmmo << std::endl;
		player_model->setRegularAmmo(newAmmo);
		player_model->setAoeAmmo(1);
	}
}