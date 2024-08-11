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

}