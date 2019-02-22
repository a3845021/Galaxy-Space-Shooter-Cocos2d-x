#pragma once

#include "Ammunition.h" 

#include "cocos2d.h" 
  
///////////////////////////////////////////////////////// Base class /////////////////////////////////////////////////////////

class CommonEnemyAmmunition : public Ammunition
{
public:
	CommonEnemyAmmunition(const int& damageAmount);

	void StartTraveling(const cocos2d::Vec2& enemyCurrentPosition, const cocos2d::Vec2& destinationPosition) override;
	void StopTraveling() override;
};
 
///////////////////////////////////////////////////////// Drived class /////////////////////////////////////////////////////////

class EnemyAmmunitionLevel1 : public CommonEnemyAmmunition
{
public:
	EnemyAmmunitionLevel1(cocos2d::Scene* scene, const int& damageAmount);

	void StartTraveling(const cocos2d::Vec2& enemyCurrentPosition, const cocos2d::Vec2& destinationPosition) override;
	void StopTraveling() override;
};

class EnemyAmmunitionLevel2 : public CommonEnemyAmmunition
{
public:
	EnemyAmmunitionLevel2(cocos2d::Scene* scene, const int& damageAmount);

	void StartTraveling(const cocos2d::Vec2& enemyCurrentPosition, const cocos2d::Vec2& destinationPosition) override;
	void StopTraveling() override;
};

class EnemyAmmunitionLevel3 : public CommonEnemyAmmunition
{
public:
	EnemyAmmunitionLevel3(cocos2d::Scene* scene, const int& damageAmount);

	void StartTraveling(const cocos2d::Vec2& enemyCurrentPosition, const cocos2d::Vec2& destinationPosition) override;
	void StopTraveling() override;
};