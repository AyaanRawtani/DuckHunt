#include "Player/PlayerModel.h"

namespace Player
{


	PlayerModel::PlayerModel() 
	{

	}

	PlayerModel::~PlayerModel() {};

	void PlayerModel::initialize()
	{
		reset();
		
	}

	void PlayerModel::reset()
	{
		player_lives = health;
		currentAmmoPerRound = ammoPerRound;
		//ammoPerRound = 3;
		currentAOEAmmoPerRound = 1;
		score = 0;
	}

	int PlayerModel::getPlayerScore()
	{
		return score;
	}
	void PlayerModel::setPlayerScore(int score)
	{
		score = score;
	}

	int PlayerModel::getPlayerLives()
	{
		return player_lives;
	}
	void PlayerModel::setPlayerLives(int lives)
	{
		player_lives = lives;
	}
	int PlayerModel::getRegularAmmo() const
	{
		return currentAmmoPerRound;
	}
	void PlayerModel::setRegularAmmo(int ammo)
	{
		currentAmmoPerRound = ammo;
	}
	int PlayerModel::getAoeAmmo() const
	{
		return currentAOEAmmoPerRound;
	}
	void PlayerModel::setAoeAmmo(int ammo)
	{
		currentAOEAmmoPerRound = ammo;
	}
	

	void PlayerModel::resetAmmo()
	{
		currentAmmoPerRound = ammoPerRound;
		currentAOEAmmoPerRound = AOEAmmoRound;
	}
}