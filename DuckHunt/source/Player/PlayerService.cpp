#include "Player/PlayerService.h"
#include "Global/ServiceLocator.h"


namespace Player
{
	using namespace Global;
	

	PlayerService::PlayerService()
	{
		player_controller = new PlayerController();
		
	}

	PlayerService::~PlayerService()
	{
		delete(player_controller);
	}

	void PlayerService::initialize()
	{
		player_controller->initialize();
	}

	void PlayerService::update()
	{
		player_controller->update();
	}

	void PlayerService::reset()
	{
		player_controller->reset();
	}



	void PlayerService::resetAmmo()
	{
		player_controller->resetAmmo();
	}

	int PlayerService::getRegularAmmo() const
	{
		return player_controller->getRegularAmmo();
	}

	void PlayerService::setRegularAmmo(int ammo)
	{
		player_controller->setRegularAmmo(ammo);
	}

	int PlayerService::getAoeAmmo() const
	{
		return  player_controller->getAoeAmmo();
	}

	void PlayerService::setAoeAmmo(int ammo)
	{
		player_controller->setAoeAmmo(ammo);
	}

	void PlayerService::increaseAmmo()
	{
		player_controller->increaseAmmo();
	}

	void PlayerService::loseLife()
	{
	    player_controller->loseLife();
	}

	int PlayerService::getLives()
	{
		return player_controller->getLives();
	}

	int PlayerService::getScore()
	{
		return player_controller->getScore();
	}

}