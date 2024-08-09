#pragma once
#include "header/Graphics/GraphicService.h"
#include "header/Event/EventService.h"
#include "header/Enemy/EnemyService.h"
#include "header/Time/TimeService.h"

using namespace Enemy;
using namespace Graphic;
using namespace Event;
using namespace Time;

namespace Global 
{

	class ServiceLocator
	{


	private:

		GraphicService* graphic_service;
		EventService* event_service;
		EnemyService* enemy_service;
		TimeService* time_service;

		ServiceLocator();
		~ServiceLocator();

		void createAllServices();
		void clearAllServices();

	public:

		static ServiceLocator* getInstance();

		void initialize();
		void update();
		void render();

		GraphicService* getGraphicService();
		EventService* getEventService();
		EnemyService* getEnemyService();
		TimeService* getTimeService();
	};
}