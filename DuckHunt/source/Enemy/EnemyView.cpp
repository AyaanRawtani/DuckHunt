#include "Enemy/EnemyView.h"
#include "Enemy/EnemyController.h"
#include "Global/ServiceLocator.h"
#include "Graphics/GraphicService.h"


using namespace Global;

namespace Enemy
{
	EnemyView::EnemyView()
	{

	}

	EnemyView::~EnemyView()
	{

	}

	void EnemyView::initialize(EnemyController* controller)
	{
		enemy_controller = controller;
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		intializeEnemySprite();
	}

	void EnemyView::intializeEnemySprite()
	{
		if (enemy_texture.loadFromFile(enemy_texture_path))
		{
			enemy_sprite.setTexture(enemy_texture);
			scaleEnemySprite();
		}
	}

	void EnemyView::scaleEnemySprite()
	{
		enemy_sprite.setScale
		(
			static_cast<float>(enemy_sprite_width) / enemy_sprite.getTexture()->getSize().x,
			static_cast<float>(enemy_sprite_height) / enemy_sprite.getTexture()->getSize().y
		);
	}

	void EnemyView::update()
	{
		enemy_sprite.setPosition(enemy_controller->getEnemyPosition());
		
	}

	void EnemyView::render()
	{
		game_window->draw(enemy_sprite);
	}
	const float EnemyView::getSpriteWidth()
	{
		return enemy_sprite_width;
	}
	const float EnemyView::getSpriteHeight()
	{
		return enemy_sprite_height;
	}
}