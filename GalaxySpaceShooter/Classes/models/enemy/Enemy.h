#pragma once

#include "models/Model.h" 
#include "models/Shooter.h"
#include "models/IDamagable.h" 

#include "cocos2d.h"

class Enemy : public Model, public Shooter
{
private:  
	// The explosion sprite with animation
	cocos2d::Sprite* mEnemyExplosionSprite;

	// Keep track of the health of the aircraft 
	int mDamageAmount;

	// Is this enemy able to shoot
	bool mIsAbleToShoot; 

	// Keep track of the health multiplier after resurrecting this enemy
	int mHealthMultiplier;

	// Store the traveling action
	cocos2d::Action* travelingAction;
	 
public:
	Enemy(cocos2d::Scene* scene, const std::string& spritePath1, const std::string& spritePath2, 
		const int& damageAmount, const bool& isAbleToShoot, const int& zOrder, const int& healthMultiplier);

	int GetDamageAmount() const;
	bool IsAbleToShoot() const;

	void StartAttacking(cocos2d::Vec2 aircraftCurrentPosition); 
	void StopAttacking(); 
	  
	// Implemented methods
	void Update() override;
	void Shoot(const int& ammunitionIndexKey, const int& shootingGrade, const cocos2d::Vec2& origin) const override;
	void Damage(int takenHealth) override;
};