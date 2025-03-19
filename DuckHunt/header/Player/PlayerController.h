#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Graphics/GraphicService.h"
#include "Enemy/EnemyController.h"
#include "Player/PlayerModel.h"



namespace Player
{
	using namespace Graphic;
	using namespace Enemy;

	class PlayerModel;

	class PlayerController
	{
	private :

		PlayerModel* player_model;

		std::vector<EnemyController*> enemies_list;
		sf::RenderWindow* game_window;

		bool pressed_left_mb();
		bool pressed_right_mb();

	public :
		PlayerController();
		~PlayerController();

		void initialize();
		void reset();
		void resetAmmo();
		void update();


		int getRegularAmmo() const;
		void setRegularAmmo(int ammo);
		int getAoeAmmo() const;
		void setAoeAmmo(int ammo);

		void increaseAmmo();

		void handleLeftMouseClick();
		void handleRightMouseClick();

		void loseLife();
		int getLives();
		
		int getScore();
		void increaseScore(int increaseAmount);

		void reduceAmmo();
		void reduceAOEAmmo();


		//void checkAmmo();

	};

}