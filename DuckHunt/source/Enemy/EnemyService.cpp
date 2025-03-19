#include "Enemy/EnemyService.h"
#include "Enemy/EnemyController.h"
#include "Global/ServiceLocator.h"
#include "Enemy/EnemyModel.h"
#include "Enemy/EnemyConfig.h"
#include "Enemy/Controllers/GreenBirdController.h"
#include "Enemy/Controllers/RedBirdController.h"

namespace Enemy
{
	using namespace Time;
	using namespace Controller;

	EnemyService::EnemyService()
	{
		std::srand(static_cast<unsigned>(std::time(nullptr)));
	}

	EnemyService::~EnemyService()
	{
		destroy();
	}

	void EnemyService::initialize()
	{
		spawnEnemy();
	}

	void EnemyService::update()
	{
	
		for (int i = 0; i < enemy_list.size(); i++)
			enemy_list[i]->update();
	}

	void EnemyService::render()
	{
		for (int i = 0; i < enemy_list.size(); i++)
			enemy_list[i]->render();
	}

	void EnemyService::reset()
	{
		destroy();
	}

	

	EnemyController* EnemyService::createEnemy(EnemyKind enemy_type)
	{
		switch (enemy_type)
		{
		case::Enemy::EnemyKind::GREENBIRD:
			return new GreenBirdController(Enemy::EnemyKind::GREENBIRD);

		case::Enemy::EnemyKind::REDBIRD:
			return new RedBirdController(Enemy::EnemyKind::REDBIRD);

		}
	}

	
	void EnemyService::spawnEnemy()
	{
			EnemyController* enemy_controller = createEnemy(getRandomEnemyType());
			enemy_controller->initialize();
			enemy_controller->setEnemyVelocity(enemy_model->getRandomVelocity());
			enemy_list.push_back(enemy_controller);
			
	}

	void EnemyService::spawnEnemiesForCurrentWave(int enemies_to_spawn)
	{
		
		//int num_enemies = current_wave + 2; 

		for (int i = 0; i < enemies_to_spawn; ++i)
		{
			spawnEnemy();
		}
	}

	int EnemyService::getRemainingEnemies()
	{
		return enemy_list.size();
	}


	int EnemyService::getCurrentWave() const
	{
		return Enemy::EnemyService::current_wave;
	}



	const std::vector<EnemyController*>& EnemyService::getEnemyVector() const
	{
		return enemy_list;
	}

	EnemyKind EnemyService::getRandomEnemyType()
	{
		int randomType = std::rand() % 2;
		return static_cast<Enemy::EnemyKind>(randomType);
	}

	void EnemyService::destroyEnemy(EnemyController* enemy_controller)
	{
		
		enemy_list.erase(std::remove(enemy_list.begin(), enemy_list.end(), enemy_controller), enemy_list.end());
		delete enemy_controller;
		if (getRemainingEnemies() <= 0 && Global::ServiceLocator::getInstance()->getPlayerService()->getLives() > 0) 
		{
			Global::ServiceLocator::getInstance()->getGameplayService()->increaseWave();
		}

	}

	void EnemyService::destroy()
	{
		
		for (EnemyController* enemy_controller : enemy_list)
		{
			delete enemy_controller;
		}
		enemy_list.clear();
	}
	
}