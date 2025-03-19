#pragma once
#include <SFML/Graphics.hpp>
#include "UI/UIElement/ImageView.h"

namespace Enemy 
{
	class EnemyController;
	enum class EnemyKind;

	class EnemyView 
	{
	private :
		const sf::String green_texture_path = "assets/textures/enemy_ship_zapper.png";
		const sf::String red_texture_path = "assets/textures/thunder_snake.png";

		const float enemy_sprite_width = 60.0f;
		const float enemy_sprite_height = 60.0f;

		EnemyController* enemy_controller;
		UI::UIElement::ImageView* enemy_image;

		sf::RenderWindow* game_window;
		sf::Texture enemy_texture;
		sf::Sprite enemy_sprite;

		void initializeImage();
		void createUIElements();
		sf::String getEnemyTexturePath();
		void destroy();

	public :
		EnemyView();
		~EnemyView();

		void initialize(EnemyController* controller);
		void update();
		void render();

		const float getSpriteWidth();
		const float getSpriteHeight();

		const sf::Sprite getEnemySprite();

		
	};

}