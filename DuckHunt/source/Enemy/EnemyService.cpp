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
		spawnEnemy(0);
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

	
	void EnemyService::spawnEnemy(int count)
	{
		//clearEnemies();
		for (int i = 0; i < count; ++i)
		{
			EnemyController* enemy_controller = createEnemy(getRandomEnemyType());
			enemy_controller->initialize();
			enemy_controller->setEnemyVelocity(enemy_model->getRandomVelocity());
			enemy_list.push_back(enemy_controller);
			
		}
		
	}

	void EnemyService::spawnEnemiesForCurrentWave(int enemies_to_spawn)
	{
		
		//int num_enemies = current_wave + 2; 

		for (int i = 0; i < enemies_to_spawn; ++i)
		{
			EnemyController* enemy_controller = createEnemy(getRandomEnemyType());
			enemy_controller->initialize(); 
			enemy_controller->setEnemyVelocity(enemy_model->getRandomVelocity());
			enemy_list.push_back(enemy_controller);
		}
	}


	int EnemyService::getCurrentWave() const
	{
		return current_wave;
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
	}

	void EnemyService::destroy()
	{
		
		for (int i = 0; i < enemy_list.size(); i++)
			delete (enemy_list[i]);
	}
	
}