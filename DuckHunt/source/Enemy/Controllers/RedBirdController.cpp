#include "Enemy/Controllers/RedBirdController.h"
#include "Enemy/EnemyModel.h"

namespace Enemy
{
	namespace Controller
	{
		RedBirdController::RedBirdController(EnemyKind type) : EnemyController(type)
		{

		}

		RedBirdController::~RedBirdController()
		{

		}

		void RedBirdController::initialize()
		{
			EnemyController::initialize();
			increaseVelocity();
		}

		void RedBirdController::increaseVelocity() 
		{
			sf::Vector2f velocity = enemy_model->getVelocity();
			velocity *= 1.5f; 
			enemy_model->setVelocity(velocity);

		}
	}
}
