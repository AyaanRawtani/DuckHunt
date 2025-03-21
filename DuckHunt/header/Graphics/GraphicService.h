#pragma once
#include <SFML/Graphics.hpp>

namespace Graphic
{


	class GraphicService
	{
	private:

		const std::string game_window_title = "Duck-Hunt";

		const int game_window_height = 1080;
		const int game_window_width = 1920;

		const sf::Color window_color = sf::Color::Blue;

		sf::VideoMode* videoMode;
		sf::RenderWindow* game_window;

		void setVideoMode();
		void onDestroy();

	public:
		GraphicService();
		~GraphicService();

		sf::RenderWindow* createGameWindow();

		void initialize();
		void update();
		void render();

		bool isGameWindowOpen();

		sf::RenderWindow* getGameWindow();
		sf::Color getWindowColor();



	};
}