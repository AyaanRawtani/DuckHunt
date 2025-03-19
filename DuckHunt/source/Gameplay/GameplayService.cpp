#include "Gameplay/GameplayService.h"
#include "Gameplay/GameplayController.h"

namespace Gameplay
{
	GameplayService::GameplayService() 
	{
		gameplay_controller = new GameplayController(); 
	}

	GameplayService::~GameplayService() 
	{
		delete (gameplay_controller); 
	}

	void GameplayService::initialize() 
	{ 
		gameplay_controller->initialize();
	}

	void GameplayService::update() 
	{ 
		gameplay_controller->update();
	}

	void GameplayService::render() 
	{
		gameplay_controller->render();
	}

	void GameplayService::increaseWave()
	{
		gameplay_controller->increaseWave();
	}
	void GameplayService::resetWave()
	{
		gameplay_controller->resetWave();
	}
	int GameplayService::getNoofEnemiesToSpawn()
	{
		return getGameplayModel()->getNoOfDucksToSpawn();
	}

	void GameplayService::reset()
	{
		gameplay_controller->reset();
	}
	GameplayModel* GameplayService::getGameplayModel()
	{
		return gameplay_controller->getGameplayModel();
	}
}