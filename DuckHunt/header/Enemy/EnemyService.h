#pragma once
#include "Enemy/EnemyController.h"
#include <vector>
#include "Enemy/EnemyModel.h"
namespace Enemy
{

	class EnemyController;

	class EnemyService
	{
	private:

		void Destroy();
		EnemyModel* enemy_model;

		std::vector<EnemyController*> enemy_list;

	public :

		

		EnemyService();
		virtual ~EnemyService();

		void initialize();
		void update();
		void render();

		void spawnEnemy(int count);

	};
}