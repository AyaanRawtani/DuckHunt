#include "Enemy/Controllers/GreenBirdController.h"
#include "Enemy/EnemyModel.h"

namespace Enemy
{

	namespace Controller
	{

		GreenBirdController::GreenBirdController(EnemyKind type) : EnemyController(type)
		{

		}
		
		GreenBirdController::~GreenBirdController()
		{

		}

		void GreenBirdController::initialize()
		{
			EnemyController::initialize();
			
		}

		
	}

}