#pragma once

#include "models/Model.h"

#include "cocos2d.h"

class Reward : public Model
{
public:
	Reward();

	void ShowUp(const cocos2d::Vec2& position);
	void HideOut();
	cocos2d::Sprite* GetSprite() const;
};

class PowerUpReward : public Reward
{
public:
	PowerUpReward(cocos2d::Scene* scene);
};

class ShootingUpgradeReward : public Reward
{
public:
	ShootingUpgradeReward(cocos2d::Scene* scene);
};