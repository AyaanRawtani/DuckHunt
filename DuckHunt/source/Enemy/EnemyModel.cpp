#include "Enemy/EnemyModel.h"
#include "Enemy/EnemyConfig.h"


namespace Enemy
{

	enum class EnemyKind;
	enum class EnemyState;

	EnemyModel::EnemyModel(EnemyKind type) 
	{
		enemy_type = type;
	}

	EnemyModel::~EnemyModel() 
	{

	}

	void EnemyModel::initialize()
	{
		
		enemy_state = EnemyState::FLYING;
		enemy_position = reference_position;
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

	EnemyState EnemyModel::getEnemyState()
	{
		return enemy_state;
	}

	void EnemyModel::setEnemyState(EnemyState state)
	{
		enemy_state = state;
	}

	EnemyKind EnemyModel::getEnemyType()
	{
		return enemy_type;
	}

	void EnemyModel::setEnemyType(EnemyKind type)
	{
		enemy_type = type;
	}

	sf::Vector2f EnemyModel::getRandomVelocity()
	{
		{
			float x = std::rand() % 151 + 250;				//getting x velocity b/w 350 and 500 
			float y = std::rand() %	121 - 350;				//getting y velo and putting in negative coz we want the birds to go up 

			if (std::rand() % 2 == 0) {
				x = -x;										// inversing so right or left gets picked 
			}

			return sf::Vector2f(x, y);
		}
		
	}
	
	sf::Vector2f EnemyModel::getVelocity()
	{
		
		return enemy_velocity;
	}

	void EnemyModel::setVelocity(sf::Vector2f velocity)
	{
		enemy_velocity = velocity;

	}

	
}