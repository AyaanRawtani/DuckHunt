#include "Enemy/EnemyModel.h"


namespace Enemy
{

	

	EnemyModel::EnemyModel() 
	{
		
	}

	EnemyModel::~EnemyModel() 
	{

	}

	void EnemyModel::initialize()
	{
		//generateRandomVelocity();
		
		enemy_position = reference_position;
		enemy_velocity = reference_velocity;

		enemy_velocity = getRandomVelocity();
	}

	sf::Vector2f EnemyModel::getEnemyPosition()
	{
		return enemy_position;
	}

	void EnemyModel::setEnemyPosition(sf::Vector2f position)
	{
		enemy_position = position;
	}
	
	

	sf::Vector2f EnemyModel::getReferencePosition()
	{
		return reference_position;
	}

	void EnemyModel::setReferencePosition(sf::Vector2f position)
	{
		reference_position = position;
	}

	sf::Vector2f EnemyModel::getReferenceVelocity()
	{
		return reference_velocity;
	}

	void EnemyModel::setReferenceVelocity(sf::Vector2f velocity)
	{
		reference_velocity = velocity;
	}

	sf::Vector2f EnemyModel::getRandomVelocity()
	{
		{
			float x = std::rand() %  151 + 350;
			float y = std::rand() % -121 - 220;

			if (std::rand() % 2 == 0) {
				x = -x;
				//y = y;
			}

			return sf::Vector2f(x, y);
		}
		
	}
	
	sf::Vector2f EnemyModel::getVelocity()
	{
		//enemy_velocity = generateRandomVelocity();
		return enemy_velocity;
	}

	void EnemyModel::setVelocity(sf::Vector2f velocity)
	{
		enemy_velocity = velocity;

	}

	
}