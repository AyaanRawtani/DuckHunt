#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Graphics/GraphicService.h"
#include "Enemy/EnemyController.h"



namespace Player
{
	using namespace Graphic;
	using namespace Enemy;

	class PlayerController
	{
	private :

		std::vector<EnemyController*> enemies_list;
		sf::RenderWindow* game_window;

		bool pressed_left_mb();
		bool pressed_right_mb();

	public :
		PlayerController();
		~PlayerController();

		void initialize();
		void update();

		void handleLeftMouseClick();
		void handleRightMouseClick();
	

	};

}