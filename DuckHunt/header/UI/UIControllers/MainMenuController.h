#pragma once
#include <SFML/Graphics.hpp>
#include "UI/IUIController.h"

namespace UI
{
	namespace MainMenu
	{
		class MainMenuUIController : public UI::Interface::IUIController
		{
		private:

			const sf::String background_texture_path = "assets/textures/bg_duckhunt.png";
			const sf::String play_button_texture_path = "assets/textures/play_button.png";
			const sf::String quit_button_texture_path = "assets/textures/quitt_button.png";

			const float button_width = 400.f;
			const float button_height = 140.f;

			sf::RenderWindow* game_window;

			sf::Texture background_texture;
			sf::Sprite background_sprite;

			sf::Texture play_button_texture;
			sf::Sprite play_button_sprite;

			sf::Texture quit_button_texture;
			sf::Sprite quit_button_sprite;

			void initializeBGImage();
			void scaleBGImage();

			void initializeButtons();
			bool loadButtonTextureFromFile();
			void setButtonSprites();
			void scaleAllButtons();
			void scaleButton(sf::Sprite* button_to_scale);
			void positionButtons();

			void processButtonInteraction();
			bool clickedButton(sf::Sprite* button_sprite, sf::Vector2f);

			void destroy();

		public:
			MainMenuUIController();

			void initialize() override;
			void update() override;
			void render() override;

			void show() override;
			

		};
	}
}