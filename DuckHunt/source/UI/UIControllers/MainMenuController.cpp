#include "UI/UIControllers/MainMenuController.h"
#include "Main/GameService.h"
#include "Global/ServiceLocator.h"
#include "Graphics/GraphicService.h"
#include "Event/EventService.h"

namespace UI
{
	namespace MainMenu
	{
		using namespace Global;
		using namespace Graphic;
		using namespace Main;
		using namespace Event;

		MainMenuUIController::MainMenuUIController()
		{
			game_window = nullptr;
		}

		void MainMenuUIController::initialize()
		{
			game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			initializeBGImage();
			initializeButtons();
		}

		void MainMenuUIController::initializeBGImage()
		{   
			if (background_texture.loadFromFile(background_texture_path))
			{  
				background_sprite.setTexture(background_texture);
				scaleBGImage();
			}
		}

		void MainMenuUIController::scaleBGImage()
		{
			
			background_sprite.setScale(
				static_cast<float>(game_window->getSize().x) / background_sprite.getTexture()->getSize().x,
				static_cast<float>(game_window->getSize().y) / background_sprite.getTexture()->getSize().y
			);
		}

		void MainMenuUIController::initializeButtons()
		{
			
			if (loadButtonTextureFromFile())
			{
				
				setButtonSprites();
				scaleAllButtons();
				positionButtons();
			}
		}
		
		bool MainMenuUIController::loadButtonTextureFromFile()
		{
			return play_button_texture.loadFromFile(play_button_texture_path) &&			
				quit_button_texture.loadFromFile(quit_button_texture_path);
		}

		void MainMenuUIController::setButtonSprites()
		{
			play_button_sprite.setTexture(play_button_texture);
			quit_button_sprite.setTexture(quit_button_texture);
		}


		void MainMenuUIController::scaleAllButtons()
		{
			scaleButton(&play_button_sprite);
			scaleButton(&quit_button_sprite);
		}

		void MainMenuUIController::scaleButton(sf::Sprite* button_to_scale)
		{
			button_to_scale->setScale(
				button_width / button_to_scale->getTexture()->getSize().x,
				button_height / button_to_scale->getTexture()->getSize().y
			);
		}

		void MainMenuUIController::positionButtons()
		{
			float x_position = (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;

			play_button_sprite.setPosition({ x_position, 600.f });
			quit_button_sprite.setPosition({ x_position, 800.f });
		}

		void MainMenuUIController::processButtonInteraction()
		{
			sf::Vector2f mouse_position = sf::Vector2f(sf::Mouse::getPosition(*game_window));

			if (clickedButton(&play_button_sprite, mouse_position))
			{
				GameService::setGameState(GameState::GAMEPLAY);
			}


			if (clickedButton(&quit_button_sprite, mouse_position))
				game_window->close();

		}

		bool MainMenuUIController::clickedButton(sf::Sprite* button_sprite, sf::Vector2f mouse_position)
		{
			EventService* event_service = ServiceLocator::getInstance()->getEventService();
			return event_service->pressedLeftMouseButton() && button_sprite->getGlobalBounds().contains(mouse_position);
		}

		void MainMenuUIController::update()
		{
			processButtonInteraction();
		}

		void MainMenuUIController::render()
		{
			game_window->draw(background_sprite);
			game_window->draw(play_button_sprite);
			game_window->draw(quit_button_sprite);
		}

		void MainMenuUIController::show()
		{
			
		}

		void MainMenuUIController::destroy()
		{

		}
	}
}