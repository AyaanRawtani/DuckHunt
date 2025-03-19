#include "UI/UIControllers/GameplayUIController.h"
#include "Global/ServiceLocator.h"
#include "Gameplay/GameplayService.h"
#include "Main/GameService.h"
#include "Player/PlayerController.h"
#include "Global/Config.h"

namespace UI
{
	namespace GameplayUI

	{
		using namespace Main;
		using namespace UIElement;
		using namespace Player;
		using namespace Global;
       // using namespace Wave;


		void GameplayUIController::createUIElements()
		{
			backgroundImage = new UIElement::ImageView();
			bulletImage = new UIElement::ImageView();
			radiusBulletImage = new UIElement::ImageView();
			healthTextView = new UIElement::TextView();
			scoreTextView = new UIElement::TextView();
			waveNoTextView = new UIElement::TextView();
			waveTimeTextView = new UIElement::TextView();
			waveStartTextView = new UIElement::TextView();
			waveStartsInTextView = new UIElement::TextView();
		}
		void GameplayUIController::initializeImage()
		{
			sf::RenderWindow* gameWindow = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			backgroundImage->initialize(Config::backgroundTexturePath, gameWindow->getSize().x, gameWindow->getSize().y, sf::Vector2f(0.f, 860.f));
			backgroundImage->setTextureRect(sf::IntRect(0, 158, 393, 42));
			bulletImage->initialize(Config::bulletTexturePath, bulletImageWidth, bulletImageHeight, bulletImagePosition);
			radiusBulletImage->initialize(Config::bulletTexturePath, bulletImageWidth, bulletImageHeight, radiusBulletImagePosition);
			

		}

		void GameplayUIController::initializeText()
		{
			player_service = ServiceLocator::getInstance()->getPlayerService();
			sf::String healthString = "Health: " + std::to_string(player_service->getLives());
			healthTextView->initialize(healthString, healthTextPosition, UIElement::FontType::BUBBLE_BOBBLE, mainfontSize, textColor);

			sf::String scoreString = "Score: " + std::to_string(player_service->getScore());
			scoreTextView->initialize(scoreString, scoreTextPosition, UIElement::FontType::BUBBLE_BOBBLE, mainfontSize, textColor);

			gameplay_model = ServiceLocator::getInstance()->getGameplayService()->getGameplayModel();
			sf::String waveNoString = "Wave NO: " + std::to_string(gameplay_model->getWaveNO());
			waveNoTextView->initialize(waveNoString, waveNoTextPosition, UIElement::FontType::BUBBLE_BOBBLE, mainfontSize, textColor);
			sf::String waveTimeString = std::to_string(gameplay_model->getWaveTime());
			waveTimeTextView->initialize(waveTimeString, waveTimeTextPosition, UIElement::FontType::BUBBLE_BOBBLE, smallFontSize, textColor);

			waveStartTextView->initialize("Wave Starts In", waveStartTextPosition, UIElement::FontType::BUBBLE_BOBBLE, waveStartfontSize, textColor);
			sf::String waveStartTimeString = std::to_string(gameplay_model->getWaveStartTime());
			waveStartsInTextView->initialize(waveStartTimeString, waveStartsInTextPosition, UIElement::FontType::BUBBLE_BOBBLE, waveStartInFontSize, textColor);


		}


		void GameplayUIController::destroy()
		{
			delete backgroundImage;
			delete bulletImage;
			delete radiusBulletImage;
			delete healthTextView;
			delete scoreTextView;
			delete waveNoTextView;
			delete waveTimeTextView;
		}

		void GameplayUIController::updateHealthText()
		{
			sf::String healthString = "Health: " + std::to_string(player_service->getLives());
			healthTextView->setText(healthString);
		}

		void GameplayUIController::updateScoreText()
		{
			sf::String scoreString = "Score: " + std::to_string(player_service->getScore());
			scoreTextView->setText(scoreString);
		}

		void GameplayUIController::updateWaveNOText()
		{
			sf::String waveNoString = "Wave NO: " + std::to_string(gameplay_model->getWaveNO());
			waveNoTextView->setText(waveNoString);
		}

		void GameplayUIController::updateWaveTimeText()
		{
			sf::String waveTimeString = std::to_string(gameplay_model->getWaveTime());
			waveTimeTextView->setText(waveTimeString);
		}

		void GameplayUIController::updateWaveStartText()
		{
			sf::String waveStartTimeString = std::to_string(gameplay_model->getWaveStartTime());
			waveStartTextView->setText("Wave Starts In");
			waveStartsInTextView->setText(waveStartTimeString);
		}

		void GameplayUIController::drawBulletCount()
		{
			for (int i = 0; i < player_service->getRegularAmmo(); i++)
			{
				bulletImage->setPosition(sf::Vector2f(bulletImagePosition.x + (i * bulletSpacing), bulletImagePosition.y));
				bulletImage->render();
			}
		}

		void GameplayUIController::drawRadiusBulletCount()
		{
			for (int i = 0; i < player_service->getAoeAmmo(); i++)
			{
				radiusBulletImage->setPosition(sf::Vector2f(radiusBulletImagePosition.x + (i * bulletSpacing), radiusBulletImagePosition.y));
				radiusBulletImage->render();
			}
		}

		GameplayUIController::GameplayUIController()
		{
			createUIElements();
		}

		GameplayUIController::~GameplayUIController()
		{
			destroy();
		}

		void GameplayUIController::initialize()
		{
			GameplayState::WAVE_STARTING;
			initializeImage();
			initializeText();
			
		}

		void GameplayUIController::update()
		{
			switch (gameplay_model->getGameplayState())
			{
			case GameplayState::WAVE_STARTING:
				updateWaveStartText();

				break;
			case GameplayState::WAVE_STARTED:
				updateHealthText();
				updateScoreText();
				updateWaveNOText();
				updateWaveTimeText();
				break;
			default:
				break;
			}


		}

		void GameplayUIController::render()
		{


			backgroundImage->render();
			healthTextView->render();
			scoreTextView->render();
			waveNoTextView->render();
			waveTimeTextView->render();

			if (gameplay_model->getGameplayState() == GameplayState::WAVE_STARTING) {
				waveStartTextView->render();
				waveStartsInTextView->render();
			}
			drawBulletCount();
			drawRadiusBulletCount();
		}

		void GameplayUIController::show()
		{
			backgroundImage->show();
			healthTextView->show();
			scoreTextView->show();
			bulletImage->show();
			waveStartTextView->show();
			waveStartsInTextView->show();
			radiusBulletImage->show();
		}

	}
}