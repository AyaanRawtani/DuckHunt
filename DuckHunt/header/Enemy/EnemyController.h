#pragma once
#include <SFML/Graphics.hpp>
#include "../header/Graphics/GraphicService.h"


namespace Enemy
{
	using namespace Graphic;
	
	class EnemyModel;
	class EnemyView;

	enum class EnemyKind;
	enum class EnemyState;

	class EnemyController
	{
	private :
		
	
		const float leftBound = 50.f;
		const float rightBound = 1920.0f - 50.f ;
		const float topBound = 50.0f;
		const float bottomBound = 1080.0f - 50.f ;

	protected :

		EnemyModel* enemy_model;
		EnemyView* enemy_view;
		void moveAndRebound();

	public :

		

		EnemyController(EnemyKind type);
		virtual ~EnemyController();

		

		virtual void initialize();
		void update();
		void render();

		sf::Vector2f getEnemyPosition();
		sf::Vector2f getEnemyVelocity();
		sf::Vector2f setEnemyVelocity(sf::Vector2f velocity);

		EnemyKind getEnemyType();
		EnemyState getEnemyState();

		bool checkCollision(const sf::Vector2i& mousePos);

		void destroy();
		
	};

}