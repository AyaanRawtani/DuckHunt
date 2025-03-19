#include "header/Gameplay/GameplayModel.h"
#include "header/Global/ServiceLocator.h"

namespace Gameplay {
    void GameplayModel::updateWaveStartTime()
    {
        elapsedTime += Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
        if (elapsedTime >= 1.f) {
            waveStartTime -= 1;
            elapsedTime = 0.f;
            if (waveStartTime <= 0) {
                //Global::ServiceLocator::getInstance()->getPlayerService()->reset();
                Global::ServiceLocator::getInstance()->getGameplayService()->resetWave();
                Global::ServiceLocator::getInstance()->getEnemyService()->spawnEnemiesForCurrentWave(getNoOfDucksToSpawn());
                gameplayState = GameplayState::WAVE_STARTED;
            }
        }
    }
    void GameplayModel::updateCurrentWaveTime()
    {
        elapsedTime += Global::ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
        if (elapsedTime >= 1.f) {
            currentWaveTime -= 1;
            elapsedTime = 0.f;
            if (currentWaveTime <= 0) {
                Global::ServiceLocator::getInstance()->getPlayerService()->loseLife();
               // Global::ServiceLocator::getInstance()->getPlayerService()->reset();
                Global::ServiceLocator::getInstance()->getGameplayService()->resetWave();
            }
        }
    }
    GameplayModel::GameplayModel()
    {
    }
    GameplayModel::~GameplayModel()
    {
    }
    void GameplayModel::initialize()
    {
        reset();
    }
    void GameplayModel::update()
    {
        switch (gameplayState)
        {
        case Gameplay::GameplayState::WAVE_STARTING:
            updateWaveStartTime();
            break;
        case Gameplay::GameplayState::WAVE_STARTED:
            updateCurrentWaveTime();
            break;
        default:
            break;
        }



    }
    int GameplayModel::getWaveNO()
    {
        return waveNO;
    }
    int GameplayModel::getNoOfDucksToSpawn()
    {
        return noOfDucksToSpawn;
    }

    int GameplayModel::getWaveTime()
    {
        return currentWaveTime;
    }
    int GameplayModel::getWaveStartTime()
    {
        return waveStartTime;
    }
    GameplayState GameplayModel::getGameplayState()
    {
        return gameplayState;
    }
    void GameplayModel::reset()
    {
        noOfDucksToSpawn = initialDucksToSpawn;
        waveStartTime = 3;
        waveNO = 1;
        currentWaveTime = waveTime;
    }
    void GameplayModel::increaseWave()
    {
        noOfDucksToSpawn = 3 + waveNO / 2;
        waveNO += 1;
        resetWave();
    }
    void GameplayModel::resetWave()
    {
        waveStartTime = 3;
        currentWaveTime = waveTime;
        
    }
    void GameplayModel::setWaveNo(int newWaveNO)
    {
        waveNO = newWaveNO;
    }
    void GameplayModel::setWaveTime(int newWaveTime)
    {
        waveTime = newWaveTime;
        currentWaveTime = waveTime;
    }
    void GameplayModel::setGameplayState(GameplayState state)
    {
        gameplayState = state;
    }
    void GameplayModel::setNoOfDucksToSpawn(int number)
    {
        noOfDucksToSpawn = number;
    }

    void GameplayModel::resetWaveTime()
    {
        waveStartTime = 3;
        currentWaveTime = waveTime;
    }
}