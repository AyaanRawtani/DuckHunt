#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window.hpp>

namespace Event
{
	enum class ButtonState
	{
		PRESSED,
		HELD,
		RELEASED,
	};

	class EventService
	{
	private:

		ButtonState left_mouse_button_state;
		ButtonState right_mouse_button_state;

		sf::Event game_event;
		sf::RenderWindow* game_window;

		bool isGameWindowOpen();
		bool gameWindowWasClosed();
		bool hasQuitGame();
		
		void updateMouseButtonsState(ButtonState& current_button_state, sf::Mouse::Button mouse_button);

	public:

		EventService();
		~EventService();

		void initialize();
		void update();
		void processEvents();
		bool pressedEscapeKey();
		bool isKeyBoardEvent();

		bool pressedLeftMouseButton();
		bool pressedRightMouseButton();


	};
}