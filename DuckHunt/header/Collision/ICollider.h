#pragma once
#include <SFML/Graphics.hpp>

namespace Collision
{
	enum class CollisionState
	{
		ENABLED,
		DISABLED,
	};

	class ICollider
	{
	private :
		CollisionState collision_state;

	public :
		ICollider();
		virtual ~ICollider();
		virtual const sf::Sprite& getColliderSprite() = 0;
		virtual void onCollision(ICollider* player_collider) = 0;

		void enableCollision();
		void disableCollision();
		CollisionState getCollisionState();
	};
}