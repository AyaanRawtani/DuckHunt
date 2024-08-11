#include "Enemy/EnemyView.h"
#include "Enemy/EnemyController.h"
#include "Global/ServiceLocator.h"
#include "Graphics/GraphicService.h"
#include "Enemy/EnemyConfig.h"


namespace Enemy
{

	using namespace Global;
	using namespace UI::UIElement;

	EnemyView::EnemyView()
	{
		createUIElements();
	}

	EnemyView::~EnemyView()
	{
		destroy();
	}

	void EnemyView::initialize(EnemyController* controller)
	{
		enemy_controller = controller;
		//game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		initializeImage();
	}


	void EnemyView::createUIElements()
	{
		enemy_image = new ImageView();
	}

	void EnemyView::initializeImage()
	{
		enemy_image->initialize(getEnemyTexturePath(), enemy_sprite_height, enemy_sprite_width, enemy_controller->getEnemyPosition());
	}

	sf::String EnemyView::getEnemyTexturePath()
	{
		switch (enemy_controller->getEnemyType())
		{
		case::Enemy::EnemyKind::GREENBIRD:
			return green_texture_path;


		case::Enemy::EnemyKind::REDBIRD:
			return red_texture_path;

		default:
			throw std::runtime_error("Unknown enemy type encountered in getEnemyTexturePath()");
		}


	}

	void EnemyView::update()
	{
		enemy_image->update();
		enemy_image->setPosition(enemy_controller->getEnemyPosition());
	}

	

	void EnemyView::render()
	{
		enemy_image->render();
	}

	const float EnemyView::getSpriteWidth()
	{
		return enemy_sprite_width;
	}

	const float EnemyView::getSpriteHeight()
	{
		return enemy_sprite_height;
	}

	const sf::Sprite EnemyView::getEnemySprite()
	{
		return enemy_image->getSprite();
	}
	
	void EnemyView::destroy()
	{
		delete(enemy_image);
		
	}

}