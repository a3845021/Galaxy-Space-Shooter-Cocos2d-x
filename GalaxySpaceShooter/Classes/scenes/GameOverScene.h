#pragma once

#include "models/background/Background.h"

#include "cocos2d.h"

class GameOverScene : public cocos2d::Scene
{
private:
	// The background parallaxing //
	Background* mBackground;

	void update(float dt);
	void PlayAgain(cocos2d::Ref* pSender);
	void GoToMenuScene(cocos2d::Ref* pSender); 

public:
	static cocos2d::Scene* createScene();
	virtual bool init();   
	CREATE_FUNC(GameOverScene);
}; 
