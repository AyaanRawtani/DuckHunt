#pragma once
#include "header/UI/UIControllers/MainMenuController.h"
#include "header/UI/IUIController.h"

namespace UI
{
	using namespace Interface;

	class UIService
	{
	private:
		MainMenu::MainMenuUIController* main_menu_controller;

		void createControllers();
		void initializeControllers();

		IUIController* getCurrentUIController();
		void destroy();

	public:
		UIService();
		~UIService();

		void initialize();
		void update();
		void render();

		void showScreen();
	};
}