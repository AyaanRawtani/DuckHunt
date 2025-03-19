#pragma once

namespace Enemy
{
	struct EnemyAnimationConfig
	{
		float tileStart;
		float tileWidth;
		float tileHeight;
		int numberOfAnimationFrame;
		float frameDuration;

		EnemyAnimationConfig(float tileStart, float tileWidth, float tileHeight, int numberOfAnimationFrame, float frameDuration)
			: tileWidth(tileWidth), tileHeight(tileHeight), tileStart(tileStart), numberOfAnimationFrame(numberOfAnimationFrame), frameDuration(frameDuration)
		{}

	};
}