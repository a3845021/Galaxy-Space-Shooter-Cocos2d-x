#pragma once

#include "cocos2d.h"

class Background
{
private:
	// The sliding background sprites: including the background and the stars //  
	cocos2d::Sprite* mBackgroundSprite_1;
	cocos2d::Sprite* mBackgroundSprite_2;
	cocos2d::Sprite* mBackgroundStarsSprite_1;
	cocos2d::Sprite* mBackgroundStarsSprite_2; 

public:
	Background(cocos2d::Scene* scene);
 
	void Update();
	void ChangeBackground();
};
