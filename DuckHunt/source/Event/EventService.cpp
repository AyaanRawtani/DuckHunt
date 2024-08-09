#include "header/Event/EventService.h"
#include "header/Main/GameService.h"
#include "header/Graphics/GraphicService.h"
#include "header/Global/ServiceLocator.h"

namespace Event
{


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
		//processEvents();
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
