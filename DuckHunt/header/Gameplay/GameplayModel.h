#pragma once
namespace Gameplay 
{
	enum class GameplayState 
	{
		WAVE_STARTING,
		WAVE_STARTED
	};


	class GameplayModel 
	{

	private:
		GameplayState gameplayState = GameplayState::WAVE_STARTING;
		int waveNO = 1;
		int initialDucksToSpawn = 3 ;
		int noOfDucksToSpawn;
		int waveTime = 30.f;
		int waveStartTime = 3;
		int currentWaveTime = waveTime;
		float elapsedTime = 0.f;
		void updateWaveStartTime();
		void updateCurrentWaveTime();

	public:
		GameplayModel();
		~GameplayModel();
		void initialize();
		void update();

		int getWaveNO();
		int getNoOfDucksToSpawn();
		int getWaveTime();
		int getWaveStartTime();
		GameplayState getGameplayState();

		void reset();
		void increaseWave();
		void resetWave();
		void setWaveNo(int newWaveNO);
		void setWaveTime(int newWaveTime);
		void setGameplayState(GameplayState state);
		void setNoOfDucksToSpawn(int number);
		void resetWaveTime();


	};
}