#pragma once
#include <SFML/Graphics.hpp>
#include "GameplayModel.h"

namespace Gameplay
{
	class GameplayView;

	class GameplayController
	{
	private : 
		GameplayView* gameplay_view;
		GameplayModel* gameplay_model;

	public :
		GameplayController();
		~GameplayController();

		void initialize();
		void update();
		void render();

		void increaseWave();
		void resetWave();

		void reset();

		GameplayModel* getGameplayModel();
	};
}
	