#pragma once
#include <SFML/Graphics.hpp>
#include "../header/Graphics/GraphicService.h"


namespace Enemy
{
	using namespace Graphic;
	

	class EnemyModel;
	class EnemyView;

	class EnemyController
	{
	private :
		EnemyView* enemy_view;
		EnemyModel* enemy_model;

		const float leftBound = 50.f;
		const float rightBound = 1920.0f - 50.f ;
		const float topBound = 50.0f;
		const float bottomBound = 1080.0f - 50.f ;

		//sf::Vector2f set_velocity;

	public :

		EnemyController();
		~EnemyController();

		void moveAndRebound();

		void initialize();
		void update();
		void render();

		sf::Vector2f getEnemyPosition();
		sf::Vector2f getEnemyVelocity();
		sf::Vector2f setEnemyVelocity(sf::Vector2f velocity);
		//sf::Vector2f generateRandomVelocity();
	};

}