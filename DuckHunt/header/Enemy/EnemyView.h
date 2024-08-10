#pragma once
#include <SFML/Graphics.hpp>

namespace Enemy 
{
	class EnemyController;

	class EnemyView 
	{
	private :
		const sf::String enemy_texture_path = "assets/textures/enemy_ship_zapper.png";

		const float enemy_sprite_width = 60.0f;
		const float enemy_sprite_height = 60.0f;

		EnemyController* enemy_controller;

		sf::RenderWindow* game_window;
		sf::Texture enemy_texture;
		sf::Sprite enemy_sprite;

		void intializeEnemySprite();
		void scaleEnemySprite();

	public :
		EnemyView();
		~EnemyView();

		void initialize(EnemyController* controller);
		void update();
		void render();

		
		const float getSpriteHeight();

	};

}