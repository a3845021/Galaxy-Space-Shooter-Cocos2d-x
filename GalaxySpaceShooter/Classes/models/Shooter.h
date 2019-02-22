#pragma once

#include <map>
#include <vector>

#include "models/ammunition/Ammunition.h"
#include "models/IDamagable.h"

#include "cocos2d.h"

class Shooter : public IDamagable
{
protected:
	// Keep track of the current health of the shooter
	int mCurrentHealth;
	
	// Keep track of the frame count for shooting
	int mShootingFrameCount;

	// The ammunition spawning map controller 
	std::map<int,std::vector<Ammunition*>> mMapOfVectorsOfAmmunitions;

	// Keep track of the life state
	bool mIsDead;

public:
	Shooter(const int& healthMultiplier);

	bool IsDead() const;
	std::vector<Ammunition*> GetAVectorOfActiveAmmunitions() const;

	virtual void Update() = 0;
	virtual void Shoot(const int& ammunitionIndexKey, const int& shootingGrade, const cocos2d::Vec2& origin) const = 0;
};
