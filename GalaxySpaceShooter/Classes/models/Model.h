#pragma once
  
#include "cocos2d.h"

class Model
{
protected:
	cocos2d::Sprite* mObjectSprite;
	bool mIsActive;

public:
	Model();

	bool IsActive() const;
	cocos2d::Vec2 GetCurrentPosition() const;
};