#pragma once
#include "header/Enemy/EnemyController.h"

namespace Enemy
{
	namespace Controller
	{
		class GreenBirdController : public EnemyController
		{
		private :

			EnemyModel* enemy_model;


		public :

			GreenBirdController(EnemyKind type);
			~GreenBirdController();

			void initialize() override;
			


		};
	}
}
