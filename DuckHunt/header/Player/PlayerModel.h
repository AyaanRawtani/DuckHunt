#pragma once
#include <SFML/Graphics.hpp>

namespace Player
{
	class PlayerModel
	{
	private : 
		const int health = 3;
		int ammoPerRound = 3;
		const int AOEAmmoRound = 1;

		int player_lives;
		int currentAmmoPerRound;
		int currentAOEAmmoPerRound;
		int score = 0;

	public :
		PlayerModel();
		~PlayerModel();

		void initialize();
		void reset();

		void resetAmmo();

		int getPlayerScore();
		void setPlayerScore(int score);

		int getPlayerLives();
		void setPlayerLives(int lives);

		int getRegularAmmo() const;
		void setRegularAmmo(int ammo);

		int getAoeAmmo() const;
		void setAoeAmmo(int ammo);

		
	};
}