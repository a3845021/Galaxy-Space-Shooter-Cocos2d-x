#pragma once

#include "models/Model.h" 

#include "cocos2d.h" 

class Ammunition : public Model
{ 
private: 
	int mDamageAmount;

public:
	Ammunition(const int& damageAmount);

	int GetDamageAmount() const;

	virtual void StartTraveling(const cocos2d::Vec2& origin, const cocos2d::Vec2& destinationPosition) = 0;
	virtual void StopTraveling() = 0;
};
