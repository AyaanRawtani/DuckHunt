#include "header/Main/GameService.h"
#include "header/Graphics/GraphicService.h"
#include "header/Global/ServiceLocator.h"

namespace Main
{
	

	GameState GameService::current_state = GameState::BOOT;

	GameService::GameService()
	{
		service_locator = nullptr;
		game_window = nullptr;
		current_wave = 0;
		
	}

	GameService::~GameService()
	{
		destroy();
	}

	void GameService::ignite()
	{
		service_locator = Global::ServiceLocator::getInstance();
		initialize();
	}

	void GameService::initialize()
	{
		service_locator->initialize();
		initializeVariables();
		showMainMenu();
		
	}

	void GameService::initializeVariables()
	{
		game_window = service_locator->getGraphicService()->getGameWindow();
		startNextWave();

	}

	void GameService::startNextWave()
	{
		current_wave++;
		enemies_per_wave = 2 * current_wave;
		service_locator->getEnemyService()->spawnEnemiesForCurrentWave(enemies_per_wave);
		printf("New wave has started ! \n");
	}

	void GameService::checkWaveCompletion()
	{
		const std::vector<Enemy::EnemyController*>& enemy_list = service_locator->getInstance()->getEnemyService()->getEnemyVector();
		if (enemy_list.empty())
		{
			printf("wave ended! \n");
			startNextWave();
		}
	}

	void GameService::setGameState(GameState new_state) 
	{
		current_state = new_state;
	}

	GameState GameService::getGameState() 
	{
		return current_state;
	}

	void GameService::destroy()
	{
		service_locator->deleteServiceLocator();
		//Graphic Service deleting the game_window
	}

	void GameService::showMainMenu()
	{
		setGameState(GameState::MAIN_MENU);
	}


	void GameService::update()
	{
		service_locator->getEventService()->processEvents();
		service_locator->update();
		checkWaveCompletion();
	}

	void GameService::render()
	{
		game_window->clear(service_locator->getGraphicService()->getWindowColor());
		service_locator->render();
		game_window->display();
	}

	bool GameService::isRunning()
	{
		return service_locator->getGraphicService()->isGameWindowOpen();
	}
}