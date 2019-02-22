#pragma once

#include <vector>

#include "Enemy.h" 

#include "cocos2d.h"

class EnemyManagement
{
private:
	// Keep track of the scene level index for releasing enemies
	int mSceneLevelIndex;

	// The enemies controller 
	std::vector<Enemy*> mVectorOfEnemies;

	// Keep track of the frame count for shooting
	int mReleasingFrameCount;

	void ReleaseAnEnemy(const cocos2d::Vec2& aircraftCurrentPosition) const;

public:
	EnemyManagement(cocos2d::Scene* scene, const int& sceneLevelIndex);

	void Update(const cocos2d::Vec2& aircraftPosition);
	std::vector<Enemy*> GetAVectorOfEnemies() const;
	std::vector<Enemy*> GetAVectorOfActiveEnemies() const;
};
