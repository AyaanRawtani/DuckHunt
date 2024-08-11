#pragma once
#include "header/Graphics/GraphicService.h"
#include "header/Event/EventService.h"
#include "header/Enemy/EnemyService.h"
#include "header/Time/TimeService.h"
#include "header/UI/UIService.h"
#include "header/Player/PlayerService.h"
#include "header/Gameplay/GameplayService.h"

namespace Global 
{
	using namespace Enemy;
	using namespace Graphic;
	using namespace Event;
	using namespace Time;
	using namespace UI;
	using namespace Gameplay;
	using namespace Player;


	class ServiceLocator
	{

	private:

		GraphicService* graphic_service;
		EventService* event_service;
		EnemyService* enemy_service;
		TimeService* time_service;
		UIService* ui_service;
		GameplayService* gameplay_service;
		PlayerService* player_service;

		ServiceLocator();
		~ServiceLocator();

		void createAllServices();
		void clearAllServices();

	public:

		static ServiceLocator* getInstance();

		void initialize();
		void update();
		void render();
		void deleteServiceLocator();
		
		GraphicService* getGraphicService();
		EventService* getEventService();
		EnemyService* getEnemyService();
		TimeService* getTimeService();
		UIService* getUIService();
		GameplayService* getGameplayService();
		PlayerService* getPlayerService();


	};
}