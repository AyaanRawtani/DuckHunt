#include "Enemy/EnemyService.h"
#include "Enemy/EnemyController.h"
#include "Global/ServiceLocator.h"
#include "Enemy/EnemyModel.h"

namespace Enemy
{
	

	EnemyService::EnemyService()
	{
		//enemy_list = nullptr;
	}

	EnemyService::~EnemyService()
	{
		Destroy();
	}

	void EnemyService::initialize()
	{
		spawnEnemy(3);
	}

	void EnemyService::update()
	{
		for (auto enemy : enemy_list)
		{
			enemy->update();
		}
	}

	void EnemyService::render()
	{
		for (auto enemy : enemy_list)
		{
			enemy->render();
		}
	}

	void EnemyService::spawnEnemy(int count)
	{
		for (int i = 0; i < count; ++i)
		{
			EnemyController* enemy_controller = new EnemyController();
			enemy_controller->initialize();

			
			enemy_controller->setEnemyVelocity(enemy_model->getRandomVelocity());

			enemy_list.push_back(enemy_controller);
		}
	}

	void EnemyService::Destroy()
	{
		for (auto enemy : enemy_list)
		{
			delete enemy;
		}
		enemy_list.clear();
	}


}