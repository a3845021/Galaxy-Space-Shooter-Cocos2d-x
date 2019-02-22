#pragma once

#include "Ammunition.h" 

#include "cocos2d.h" 

///////////////////////////////////////////////////////// Base class /////////////////////////////////////////////////////////

class CommonAircraftAmmunition : public Ammunition
{  
public:
	CommonAircraftAmmunition(const int& damageAmount);

	void StartTraveling(const cocos2d::Vec2& aircraftCurrentPosition, const cocos2d::Vec2& destinationPosition) override;
	void StopTraveling() override;
};

///////////////////////////////////////////////////////// Drived class /////////////////////////////////////////////////////////

class AircraftAmmunitionLevel1 : public CommonAircraftAmmunition
{
public:
	AircraftAmmunitionLevel1(cocos2d::Scene* scene, const int& damageAmount);

	void StartTraveling(const cocos2d::Vec2& aircraftCurrentPosition, const cocos2d::Vec2& destinationPosition) override;
	void StopTraveling() override;
};

class AircraftAmmunitionLevel2 : public CommonAircraftAmmunition
{
public:
	AircraftAmmunitionLevel2(cocos2d::Scene* scene, const int& damageAmount);

	void StartTraveling(const cocos2d::Vec2& aircraftCurrentPosition, const cocos2d::Vec2& destinationPosition) override;
	void StopTraveling() override;
};

class AircraftAmmunitionLevel3 : public CommonAircraftAmmunition
{
public:
	AircraftAmmunitionLevel3(cocos2d::Scene* scene, const int& damageAmount);

	void StartTraveling(const cocos2d::Vec2& aircraftCurrentPosition, const cocos2d::Vec2& destinationPosition) override;
	void StopTraveling() override;
};

class AircraftAmmunitionLevel4 : public CommonAircraftAmmunition
{
public:
	AircraftAmmunitionLevel4(cocos2d::Scene* scene, const int& damageAmount);

	void StartTraveling(const cocos2d::Vec2& aircraftCurrentPosition, const cocos2d::Vec2& destinationPosition) override;
	void StopTraveling() override;
};

class AircraftAmmunitionLevel5 : public CommonAircraftAmmunition
{
public:
	AircraftAmmunitionLevel5(cocos2d::Scene* scene, const int& damageAmount);

	void StartTraveling(const cocos2d::Vec2& aircraftCurrentPosition, const cocos2d::Vec2& destinationPosition) override;
	void StopTraveling() override;
};

class AircraftAmmunitionLevel6 : public CommonAircraftAmmunition
{
public:
	AircraftAmmunitionLevel6(cocos2d::Scene* scene, const int& damageAmount);

	void StartTraveling(const cocos2d::Vec2& aircraftCurrentPosition, const cocos2d::Vec2& destinationPosition) override;
	void StopTraveling() override;
};

class AircraftAmmunitionLevel7 : public CommonAircraftAmmunition
{
public:
	AircraftAmmunitionLevel7(cocos2d::Scene* scene, const int& damageAmount);

	void StartTraveling(const cocos2d::Vec2& aircraftCurrentPosition, const cocos2d::Vec2& destinationPosition) override;
	void StopTraveling() override;
};

class AircraftAmmunitionLevel8 : public CommonAircraftAmmunition
{
public:
	AircraftAmmunitionLevel8(cocos2d::Scene* scene, const int& damageAmount);

	void StartTraveling(const cocos2d::Vec2& aircraftCurrentPosition, const cocos2d::Vec2& destinationPosition) override;
	void StopTraveling() override;
};