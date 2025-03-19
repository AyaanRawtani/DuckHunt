#pragma once
#include "UI/IUIController.h"
#include "UI/UIElement/ImageView.h"
#include "UI/UIElement/TextView.h"
#include "Gameplay/GameplayModel.h"
#include "Player/PlayerService.h"
//#include "Waves/WaveController.h"


namespace UI
{
	namespace GameplayUI
	{
		class GameplayUIController : public UI::Interface::IUIController
		{

			Player::PlayerService* player_service;
			Gameplay::GameplayModel* gameplay_model;

			UIElement::ImageView* backgroundImage;
			UIElement::TextView* healthTextView;
			UIElement::TextView* waveNoTextView;
			UIElement::TextView* waveTimeTextView;
			UIElement::TextView* waveStartTextView;
			UIElement::TextView* waveStartsInTextView;
			UIElement::TextView* scoreTextView;
			UIElement::ImageView* bulletImage;
			UIElement::ImageView* radiusBulletImage;

			const sf::Color textColor = sf::Color::White;
			const float mainfontSize = 40.f;
			const float smallFontSize = 30.f;

			const float waveStartfontSize = 60.f;
			const float waveStartInFontSize = 50.f;
			const sf::Vector2f healthTextPosition = sf::Vector2f(1750.f, 15.f);
			const sf::Vector2f scoreTextPosition = sf::Vector2f(1750.f, 50.f);

			const sf::Vector2f waveNoTextPosition = sf::Vector2f(900.f, 15.f);
			const sf::Vector2f waveTimeTextPosition = sf::Vector2f(970.f, 60.f);
			const sf::Vector2f waveStartTextPosition = sf::Vector2f(800.f, 400.f);
			const sf::Vector2f waveStartsInTextPosition = sf::Vector2f(950.f, 460.f);



			const sf::Vector2f bulletImagePosition = sf::Vector2f(30.f, 10.f);
			const float bulletSpacing = 20.f;
			const float bulletImageWidth = 20.f;
			const float bulletImageHeight = 30.f;

			const sf::Vector2f radiusBulletImagePosition = sf::Vector2f(30.f, 40.f);

			void createUIElements();
			void initializeImage();
			void initializeText();
			void destroy();
			void updateHealthText();
			void updateScoreText();
			void updateWaveNOText();
			void updateWaveTimeText();
			void updateWaveStartText();
			void drawBulletCount();
			void drawRadiusBulletCount();
		public:
			GameplayUIController();
			virtual ~GameplayUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

		};

	}
}
