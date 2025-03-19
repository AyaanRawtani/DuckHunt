#include "header/Global/ServiceLocator.h"
#include "header/Main/GameService.h"

namespace Global
{
	using namespace Main;

	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		event_service = nullptr;
		enemy_service = nullptr;
		time_service = nullptr;
		ui_service = nullptr;
		gameplay_service = nullptr;
		player_service = nullptr;
		createAllServices();
	}


	ServiceLocator::~ServiceLocator()
	{
		clearAllServices();
	}

	void ServiceLocator::createAllServices()
	{
		graphic_service = new GraphicService();
		event_service = new EventService();
		enemy_service = new EnemyService();
		time_service = new TimeService();
		ui_service = new UIService();
		gameplay_service = new GameplayService();
		player_service = new PlayerService();
	}

	void ServiceLocator::clearAllServices()
	{
		delete(graphic_service);
		delete(event_service);
		delete(enemy_service);
		delete(time_service);
		delete(ui_service);
		delete(gameplay_service);
		delete(player_service);

	}

	void ServiceLocator::initialize()
	{
		graphic_service->initialize();
		event_service->initialize();
		enemy_service->initialize();
		time_service->initialize();
		ui_service->initialize();
		gameplay_service->initialize();
		player_service->initialize();
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	void ServiceLocator::update()
	{
		graphic_service->update();
		event_service->update();
		time_service->update();
	
		if (Main::GameService::getGameState() == Main::GameState::GAMEPLAY)
		{
			enemy_service->update();
			player_service->update();
			gameplay_service->update();
		}
		
		ui_service->update();
	}

	void ServiceLocator::render()
	{
		graphic_service->render();
		
		
		if (Main::GameService::getGameState() == Main::GameState::GAMEPLAY)
		{
			gameplay_service->render();
			enemy_service->render();
			
		}

		ui_service->render();
	}

	GraphicService* ServiceLocator::getGraphicService()
	{
		return graphic_service;
	}

	EventService* ServiceLocator::getEventService()
	{
		return event_service;
	}

	EnemyService* ServiceLocator::getEnemyService()
	{
		return enemy_service;
	}
	
	TimeService* ServiceLocator::getTimeService()
	{
		return time_service;
	}
	UIService* ServiceLocator::getUIService()
	{
		return ui_service;
	}
	GameplayService* ServiceLocator::getGameplayService()
	{
		return gameplay_service;
	}

	PlayerService* ServiceLocator::getPlayerService()
	{
		return player_service;
	}

	void ServiceLocator::deleteServiceLocator()
	{
		delete(this);
	}
}