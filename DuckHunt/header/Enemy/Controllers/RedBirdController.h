#pragma once
#include "Enemy/EnemyController.h"

namespace Enemy
{
	namespace Controller
	{
		class RedBirdController : public EnemyController
		{
		private :

			

		public :

			
			RedBirdController(EnemyKind Type);
			~RedBirdController();

			void initialize();
			void increaseVelocity();


		};
	}
}