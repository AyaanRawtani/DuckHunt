#pragma once
#include <SFML/Graphics.hpp>
#include "header/Global/ServiceLocator.h"
#include "header/Event/EventService.h"

using namespace Global;

namespace Main
{

	class GameService
	{
	private:

		ServiceLocator* service_locator;
		sf::RenderWindow* game_window;

		void initialize();
		void initializeVariables();
		void destroy();

	public:
		GameService();
		~GameService();

		void ignite();
		void update();
		void render();
		bool isRunning();

	};
}