#pragma once
#include <SFML/Graphics.hpp>
#include "UI/UIElement/ImageView.h"
#include "Enemy/EnemyAnimationConfig.h"

namespace Enemy 
{
	class EnemyController;
	enum class EnemyKind;

	class EnemyView 
	{
	private :
		const sf::String green_texture_path = "assets/textures/greenDuck.png";
		const sf::String red_texture_path = "assets/textures/redDuck.png";

		const float enemy_sprite_width = 100.0f;
		const float enemy_sprite_height = 300.0f;


		int currentFrame = 0;
		float elapsedTime;
		int flip = 1;

		EnemyController* enemy_controller;
		UI::UIElement::ImageView* enemy_image;

		sf::RenderWindow* game_window;
		sf::Texture enemy_texture;
		sf::Sprite enemy_sprite;

		bool deadAnimationFinished = false;

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


		void updateAnimation(EnemyAnimationConfig animationConfig);
		void showDeadAnimation(EnemyAnimationConfig animationConfig);

		const float getSpriteWidth();
		const float getSpriteHeight();

		const sf::Sprite getEnemySprite();

		void setScale(int flip);

		
	};

}