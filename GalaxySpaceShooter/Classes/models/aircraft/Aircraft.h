#pragma once
  
#include <vector>

#include "models/Model.h" 
#include "models/Shooter.h" 

#include "cocos2d.h"
#include "ui/CocosGUI.h"
 
class Aircraft : public Model, public Shooter
{
private:
	// The sprite represents the damaged illustration
	cocos2d::Sprite* mDamagedSprite;

	// The health bar controller;
	cocos2d::ui::LoadingBar* mHealthBar;

	// The shooting controller
	int mAmmunitionIndexKey;
	int mShootingGrade;

	// The dragging controller
	cocos2d::Vec2 mTouchOffsetPosition;

	bool mIsTouching;

	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	bool onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	bool onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

	// The level setup function 
	void SetupLevel(const int& sceneLevelIndex);

public:
	Aircraft(cocos2d::Scene* scene,const int& sceneLevelIndex); 
	  
	// Implemented methods
	void Update() override; 
	void Shoot(const int& ammunitionIndexKey, const int& shootingGrade, const cocos2d::Vec2& origin) const override;
	void Damage(int takenHealth) override;
}; 
