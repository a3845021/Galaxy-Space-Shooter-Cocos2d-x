#pragma once

#include "models/background/Background.h"

#include "cocos2d.h"

class MenuScene : public cocos2d::Scene
{
private:
	// The background parallaxing //
	Background* mBackground;  

	void update(float dt);
	void GoToGameScene(const int& selectedIndex);

public:
	static cocos2d::Scene* createScene(); 
	virtual bool init();   
	CREATE_FUNC(MenuScene);
}; 
