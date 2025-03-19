#include "Gameplay/GameplayController.h"
#include "Gameplay/GameplayView.h"
#include "Global/ServiceLocator.h"


namespace Gameplay
{
	GameplayController::GameplayController()
	{
		gameplay_model = new GameplayModel();
		gameplay_view = new GameplayView();
	}

	GameplayController::~GameplayController()
	{
		delete(gameplay_model);
		delete(gameplay_view);
	}

	void GameplayController::initialize() 
	{
		gameplay_view->initialize();
		gameplay_model->initialize();
	}

	void GameplayController::update() 
	{ 
		gameplay_view->update(); 
		gameplay_model->update();
	}

	void GameplayController::render() 
	{ 
		gameplay_view->render();
		
	}

	void GameplayController::increaseWave()
	{
		gameplay_model->setGameplayState(GameplayState::WAVE_STARTING);
		gameplay_model->increaseWave();
		Global::ServiceLocator::getInstance()->getEnemyService()->reset();
		//Global::ServiceLocator::getInstance()->getPlayerService()->resetAmmo();
		Global::ServiceLocator::getInstance()->getPlayerService()->increaseAmmo();
	}
	void GameplayController::resetWave()
	{
		gameplay_model->setGameplayState(GameplayState::WAVE_STARTING);
		gameplay_model->resetWave();
		Global::ServiceLocator::getInstance()->getEnemyService()->reset();
		Global::ServiceLocator::getInstance()->getPlayerService()->reset();
		Global::ServiceLocator::getInstance()->getPlayerService()->increaseAmmo();

	}
	void GameplayController::reset()
	{
		gameplay_model->reset();
		resetWave();
	}
	GameplayModel* GameplayController::getGameplayModel()
	{
		return gameplay_model;
	}
}