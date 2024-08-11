#pragma once
#include <SFML/Graphics.hpp>
#include "header/Global/ServiceLocator.h"


namespace Main
{
	
	enum class GameState 
	{
		BOOT,
		MAIN_MENU,
		GAMEPLAY,
	};

	class GameService
	{
	private:

		int current_wave;
		int enemies_per_wave;

		Global::ServiceLocator* service_locator;
		sf::RenderWindow* game_window;
		
		static GameState current_state;

		void initialize();
		void initializeVariables();
		void destroy();

		

		void showMainMenu();

	public:
		GameService();
		~GameService();

		static void setGameState(GameState new_state);
		static GameState getGameState();

		void ignite();
		void update();
		void render();

		bool isRunning();

		void startNextWave();
		void checkWaveCompletion();

	};
}