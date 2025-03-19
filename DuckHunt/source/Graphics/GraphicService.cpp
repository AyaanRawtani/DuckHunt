#include "header/Graphics/GraphicService.h"

namespace Graphic
{

	GraphicService::GraphicService()
	{
		game_window = nullptr;
		videoMode = nullptr;

	}

	GraphicService:: ~GraphicService()
	{
		onDestroy();
	}

	void GraphicService::initialize()
	{
		game_window = createGameWindow();
	}

	sf::RenderWindow* GraphicService::createGameWindow()
	{
		setVideoMode();
		return new sf::RenderWindow(*videoMode, game_window_title, sf::Style::Titlebar);
	}

	void GraphicService::setVideoMode()
	{
		videoMode = new sf::VideoMode(game_window_width, game_window_height, sf::VideoMode::getDesktopMode().bitsPerPixel); //sets resolution
	}

	void GraphicService::onDestroy()
	{
		delete(videoMode);
		delete(game_window);

	}


	void GraphicService::update()
	{

	}

	void GraphicService::render()
	{

	}

	bool GraphicService::isGameWindowOpen()
	{
		return game_window->isOpen();
	}

	sf::RenderWindow* GraphicService::getGameWindow()
	{
		return game_window;
	}

	sf::Color GraphicService::getWindowColor()
	{
		return window_color;
	}
}