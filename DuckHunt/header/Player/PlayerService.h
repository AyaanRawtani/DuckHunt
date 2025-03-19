#pragma once
#include "Player/PlayerController.h"


namespace Player
{
	class PlayerService
	{
	private :

		PlayerController* player_controller;
		

	public :

		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void reset();

		
		void resetAmmo();

		int getRegularAmmo() const;
		void setRegularAmmo(int ammo);
		int getAoeAmmo() const;
		void setAoeAmmo(int ammo);

		void increaseAmmo();

		void loseLife();
		int getLives();

		int getScore();
		
		

	};
}