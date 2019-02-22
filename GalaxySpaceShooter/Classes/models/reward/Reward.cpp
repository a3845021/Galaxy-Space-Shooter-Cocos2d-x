#include "Reward.h" 
 
Reward::Reward() : Model()
{
	// Constructor 
}

void Reward::ShowUp(const cocos2d::Vec2& position)
{
	mIsActive = true;
	mObjectSprite->setVisible(true);
	mObjectSprite->setPosition(position);
}

void Reward::HideOut()
{
	mIsActive = false;
	mObjectSprite->setVisible(false);
}

cocos2d::Sprite* Reward::GetSprite() const
{
	return mObjectSprite;
}

PowerUpReward::PowerUpReward(cocos2d::Scene* scene)
{
	mObjectSprite = cocos2d::Sprite::create("Sprites/Gameplay/Aircrafts Rewards/Power Up.png");
	scene->addChild(mObjectSprite, 8);
	mObjectSprite->setVisible(false);
}

ShootingUpgradeReward::ShootingUpgradeReward(cocos2d::Scene* scene)
{
	mObjectSprite = cocos2d::Sprite::create("Sprites/Gameplay/Aircrafts Rewards/Shooting Upgrade.png");
	scene->addChild(mObjectSprite, 8);
	mObjectSprite->setVisible(false);
}
