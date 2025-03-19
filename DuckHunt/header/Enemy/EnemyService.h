#pragma once
#include "Enemy/EnemyController.h"
#include <vector>
#include "Enemy/EnemyModel.h"


namespace Enemy
{
	
	class EnemyController;
	enum class EnemyKind;

	class EnemyService
	{
	private:
		int current_wave = 1;
		
		EnemyModel* enemy_model;

		std::vector<EnemyController*> enemy_list;

		EnemyKind getRandomEnemyType();
		
		EnemyController* createEnemy(EnemyKind enemy_type);

	public :

		EnemyService();
		virtual ~EnemyService();

		void initialize();
		void update();
		void render();
		void reset();

		void spawnEnemy();
		void spawnEnemiesForCurrentWave(int enemies_to_spawn);

		int getRemainingEnemies();

		int getCurrentWave() const;

		const std::vector<EnemyController*>& getEnemyVector() const;

		void destroyEnemy(EnemyController* enemy_controller);
		void destroy();
	};
}