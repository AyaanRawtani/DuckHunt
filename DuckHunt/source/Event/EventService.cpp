#include "header/Event/EventService.h"
#include "header/Main/GameService.h"
#include "header/Graphics/GraphicService.h"


namespace Event
{
	using namespace Global;

	EventService::EventService()
	{
		game_window = nullptr;

	}

	EventService::~EventService() = default;

	void EventService::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	}

	void EventService::update()
	{
		
		updateMouseButtonsState(left_mouse_button_state, sf::Mouse::Left);
		updateMouseButtonsState(right_mouse_button_state, sf::Mouse::Right);
	}

	void EventService::processEvents()
	{
		if (isGameWindowOpen())
		{
			while (game_window->pollEvent(game_event))
			{
				if (gameWindowWasClosed() || hasQuitGame())
				{
					game_window->close();
				}
			}
		}
	}

	bool EventService::hasQuitGame()
	{
		return (isKeyBoardEvent() && pressedEscapeKey());
	}

	void EventService::updateMouseButtonsState(ButtonState& current_button_state, sf::Mouse::Button mouse_button)
	{
		if (sf::Mouse::isButtonPressed(mouse_button))
		{
			switch (current_button_state)
			{
			case ButtonState::RELEASED:
				current_button_state = ButtonState::PRESSED;
				break;
			case ButtonState::PRESSED:
				current_button_state = ButtonState::HELD;
				break;
			}
		}
		else
		{
			current_button_state = ButtonState::RELEASED;
		}
	}

	bool EventService::pressedLeftMouseButton()
	{
		return left_mouse_button_state == ButtonState::PRESSED;
	}

	bool EventService::pressedRightMouseButton()
	{
		return right_mouse_button_state == ButtonState::PRESSED;
	}

	bool EventService::isKeyBoardEvent()
	{
		return game_event.type == sf::Event::KeyPressed;
	}

	bool EventService::pressedEscapeKey()
	{
		return game_event.key.code == sf::Keyboard::Escape;
	}

	bool EventService::isGameWindowOpen()
	{
		return game_window != nullptr;
	}

	bool EventService::gameWindowWasClosed()
	{
		return game_event.type == sf::Event::Closed;
	}

}
