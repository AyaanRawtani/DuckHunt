#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>

namespace Event
{


	class EventService
	{
	private:
		sf::Event game_event;
		sf::RenderWindow* game_window;

		bool isGameWindowOpen();
		bool gameWindowWasClosed();
		bool hasQuitGame();

	public:

		EventService();
		~EventService();

		void initialize();
		void update();
		void processEvents();
		bool pressedEscapeKey();
		bool isKeyBoardEvent();


	};
}