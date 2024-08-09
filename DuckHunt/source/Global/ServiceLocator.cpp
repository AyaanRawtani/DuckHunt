#include "header/Global/ServiceLocator.h"

namespace Global
{


	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		event_service = nullptr;
		enemy_service = nullptr;
		time_service = nullptr;
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
	}

	void ServiceLocator::clearAllServices()
	{
		delete(graphic_service);
		delete(event_service);
		delete(enemy_service);
		delete(time_service);

	}

	void ServiceLocator::initialize()
	{
		graphic_service->initialize();
		event_service->initialize();
		enemy_service->initialize();
		time_service->initialize();
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
		enemy_service->update();
		time_service->update();
	}

	void ServiceLocator::render()
	{
		graphic_service->render();
		enemy_service->render();
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
}