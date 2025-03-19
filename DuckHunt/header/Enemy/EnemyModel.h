#pragma once
#include <SFML/Graphics.hpp>


namespace Enemy
{
	
	enum class EnemyKind;
	enum class EnemyState;

	class EnemyModel
	{
	private :
		sf::Vector2f reference_position = sf::Vector2f(900.0f, 800.0f);
		sf::Vector2f enemy_position;

		sf::Vector2f reference_velocity = sf::Vector2f(350, -200);
		sf::Vector2f enemy_velocity;

		EnemyKind enemy_type;
		EnemyState enemy_state;

	public :
		
		EnemyModel(EnemyKind type);
		~EnemyModel();

		void initialize();

		sf::Vector2f getEnemyPosition();
		void setEnemyPosition(sf::Vector2f position);

		sf::Vector2f getReferencePosition();
		void setReferencePosition(sf::Vector2f position);

		sf::Vector2f getReferenceVelocity();
		void setReferenceVelocity(sf::Vector2f velocity);
		sf::Vector2f getRandomVelocity();
		sf::Vector2f getVelocity();
		void setVelocity(sf::Vector2f velocity);

		EnemyKind getEnemyType();
		void setEnemyType(EnemyKind type);

		EnemyState getEnemyState();
		void setEnemyState(EnemyState state);
	};
}