#pragma once

#include "models/background/Background.h" 
#include "models/aircraft/Aircraft.h" 
#include "models/enemy/EnemyManagement.h"

#include "cocos2d.h"

class GameScene : public cocos2d::Scene
{  
private:   
	// The background parallaxing
	Background* mBackground;

	// The aircraft controller
	Aircraft* mAircraft;

	// The enemies controller
	EnemyManagement* mEnemyManagement;

	// The score label
	cocos2d::Label* mScoreLable;  

	void update(float dt);
	void CheckCollision();
	 
public:
	// Keep track of the scene level index that has been chosen
	static int sSceneLevelIndex;

	// Keep track of the score
	static int sScore;

	static cocos2d::Scene* createScene(const int& levelIndex); 
	virtual bool init();   
	CREATE_FUNC(GameScene);
}; 
