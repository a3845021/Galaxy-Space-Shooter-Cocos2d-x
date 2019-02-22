#include "cmath"

#include "AircraftAmmunition.h"  
#include "common/CommonValues.h" 

///////////////////////////////////////////////////////// Base class /////////////////////////////////////////////////////////

CommonAircraftAmmunition::CommonAircraftAmmunition(const int& damageAmount) : Ammunition(damageAmount)
{
	// Constructor 
}

void CommonAircraftAmmunition::StartTraveling(const cocos2d::Vec2& aircraftCurrentPosition, const cocos2d::Vec2& destinationPosition)
{
	mIsActive = true;
	mObjectSprite->setVisible(true);

	// Set the departing position
	mObjectSprite->setPosition(aircraftCurrentPosition.x, aircraftCurrentPosition.y + AMMUNITION_POSITION_OFFSET_AIRCRAFT);

	// Find the traveling direction
	cocos2d::Vec2 rotatingDirection = (destinationPosition - mObjectSprite->getPosition()).getNormalized();

	// Set the rotation based on the direction
	mObjectSprite->setRotation(atan2(rotatingDirection.x, rotatingDirection.y) * (180.0F / M_PI));
}

void CommonAircraftAmmunition::StopTraveling()
{
	// Stop all the action that has attached to this
	mObjectSprite->stopAllActions();

	mIsActive = false;
	mObjectSprite->setVisible(false);
}

///////////////////////////////////////////////////////// Drived class /////////////////////////////////////////////////////////

///////////////////////////////////////////////////  AircraftAmmunitionLevel1 ////////////////////////////////////////////////// 

AircraftAmmunitionLevel1::AircraftAmmunitionLevel1(cocos2d::Scene* scene, const int& damageAmount) : CommonAircraftAmmunition(damageAmount)
{
	// The ammunition sprite
	mObjectSprite = cocos2d::Sprite::create("Sprites/Gameplay/Aircrafts Ammunition/Ammunition 1.png");
	scene->addChild(mObjectSprite, 2);
	mObjectSprite->setVisible(false);
}

void AircraftAmmunitionLevel1::StartTraveling(const cocos2d::Vec2& aircraftCurrentPosition, const cocos2d::Vec2& destinationPosition)
{
	CommonAircraftAmmunition::StartTraveling(aircraftCurrentPosition, destinationPosition);

	// Ammunition traveling animation // 
	auto ammunitionTravelingAction = cocos2d::MoveTo::create(AMMUNITION_TRAVELING_SPEED_AIRCRAFT * (cocos2d::Director::getInstance()->getVisibleSize().height - 0),
		mObjectSprite->getPosition() + (destinationPosition - mObjectSprite->getPosition()).getNormalized() * AIRCRAFT_AMMUNITION_DIRECTION_NORMALIZE_VALUE);

	// Callback for setting back to inactive
	auto callbackFinishedTraveling = cocos2d::CallFunc::create([=]() {
		mIsActive = false;
		mObjectSprite->setVisible(false);
	});

	mObjectSprite->runAction(cocos2d::Sequence::create(ammunitionTravelingAction, callbackFinishedTraveling, nullptr));
}

void AircraftAmmunitionLevel1::StopTraveling()
{
	CommonAircraftAmmunition::StopTraveling();
}

///////////////////////////////////////////////////  AircraftAmmunitionLevel2 ////////////////////////////////////////////////// 

AircraftAmmunitionLevel2::AircraftAmmunitionLevel2(cocos2d::Scene* scene, const int& damageAmount) : CommonAircraftAmmunition(damageAmount)
{
	// The ammunition sprite
	mObjectSprite = cocos2d::Sprite::create("Sprites/Gameplay/Aircrafts Ammunition/Ammunition 2.png");
	scene->addChild(mObjectSprite, 3);
	mObjectSprite->setVisible(false);
}

void AircraftAmmunitionLevel2::StartTraveling(const cocos2d::Vec2& aircraftCurrentPosition, const cocos2d::Vec2& destinationPosition)
{
	CommonAircraftAmmunition::StartTraveling(aircraftCurrentPosition, destinationPosition);

	// Ammunition traveling animation // 
	auto ammunitionTravelingAction = cocos2d::MoveTo::create(AMMUNITION_TRAVELING_SPEED_AIRCRAFT * (cocos2d::Director::getInstance()->getVisibleSize().height - 40),
		mObjectSprite->getPosition() + (destinationPosition - mObjectSprite->getPosition()).getNormalized() * AIRCRAFT_AMMUNITION_DIRECTION_NORMALIZE_VALUE);

	// Callback for setting back to inactive
	auto callbackFinishedTraveling = cocos2d::CallFunc::create([=]() {
		mIsActive = false;
		mObjectSprite->setVisible(false);
	});

	mObjectSprite->runAction(cocos2d::Sequence::create(ammunitionTravelingAction, callbackFinishedTraveling, nullptr));
}

void AircraftAmmunitionLevel2::StopTraveling()
{
	CommonAircraftAmmunition::StopTraveling();
}

///////////////////////////////////////////////////  AircraftAmmunitionLevel3 ////////////////////////////////////////////////// 

AircraftAmmunitionLevel3::AircraftAmmunitionLevel3(cocos2d::Scene* scene, const int& damageAmount) : CommonAircraftAmmunition(damageAmount)
{
	// The ammunition sprite
	mObjectSprite = cocos2d::Sprite::create("Sprites/Gameplay/Aircrafts Ammunition/Ammunition 3.png");
	scene->addChild(mObjectSprite, 4);
	mObjectSprite->setVisible(false);
}

void AircraftAmmunitionLevel3::StartTraveling(const cocos2d::Vec2& aircraftCurrentPosition, const cocos2d::Vec2& destinationPosition)
{
	CommonAircraftAmmunition::StartTraveling(aircraftCurrentPosition, destinationPosition);

	// Ammunition traveling animation // 
	auto ammunitionTravelingAction = cocos2d::MoveTo::create(AMMUNITION_TRAVELING_SPEED_AIRCRAFT * (cocos2d::Director::getInstance()->getVisibleSize().height - 80),
		mObjectSprite->getPosition() + (destinationPosition - mObjectSprite->getPosition()).getNormalized() * AIRCRAFT_AMMUNITION_DIRECTION_NORMALIZE_VALUE);

	// Callback for setting back to inactive
	auto callbackFinishedTraveling = cocos2d::CallFunc::create([=]() {
		mIsActive = false;
		mObjectSprite->setVisible(false);
	});

	mObjectSprite->runAction(cocos2d::Sequence::create(ammunitionTravelingAction, callbackFinishedTraveling, nullptr));
}

void AircraftAmmunitionLevel3::StopTraveling()
{
	CommonAircraftAmmunition::StopTraveling();
}

///////////////////////////////////////////////////  AircraftAmmunitionLevel4 ////////////////////////////////////////////////// 

AircraftAmmunitionLevel4::AircraftAmmunitionLevel4(cocos2d::Scene* scene, const int& damageAmount) : CommonAircraftAmmunition(damageAmount)
{
	// The ammunition sprite
	mObjectSprite = cocos2d::Sprite::create("Sprites/Gameplay/Aircrafts Ammunition/Ammunition 4.png");
	scene->addChild(mObjectSprite, 5);
	mObjectSprite->setVisible(false);
}

void AircraftAmmunitionLevel4::StartTraveling(const cocos2d::Vec2& aircraftCurrentPosition, const cocos2d::Vec2& destinationPosition)
{
	CommonAircraftAmmunition::StartTraveling(aircraftCurrentPosition, destinationPosition);

	// Ammunition traveling animation // 
	auto ammunitionTravelingAction = cocos2d::MoveTo::create(AMMUNITION_TRAVELING_SPEED_AIRCRAFT * (cocos2d::Director::getInstance()->getVisibleSize().height - 120),
		mObjectSprite->getPosition() + (destinationPosition - mObjectSprite->getPosition()).getNormalized() * AIRCRAFT_AMMUNITION_DIRECTION_NORMALIZE_VALUE);

	// Callback for setting back to inactive
	auto callbackFinishedTraveling = cocos2d::CallFunc::create([=]() {
		mIsActive = false;
		mObjectSprite->setVisible(false);
	});

	mObjectSprite->runAction(cocos2d::Sequence::create(ammunitionTravelingAction, callbackFinishedTraveling, nullptr));
}

void AircraftAmmunitionLevel4::StopTraveling()
{
	CommonAircraftAmmunition::StopTraveling();
}

///////////////////////////////////////////////////  AircraftAmmunitionLevel5 ////////////////////////////////////////////////// 

AircraftAmmunitionLevel5::AircraftAmmunitionLevel5(cocos2d::Scene* scene, const int& damageAmount) : CommonAircraftAmmunition(damageAmount)
{
	// The ammunition sprite
	mObjectSprite = cocos2d::Sprite::create("Sprites/Gameplay/Aircrafts Ammunition/Ammunition 5.png");
	scene->addChild(mObjectSprite, 6);
	mObjectSprite->setVisible(false);
}

void AircraftAmmunitionLevel5::StartTraveling(const cocos2d::Vec2& aircraftCurrentPosition, const cocos2d::Vec2& destinationPosition)
{
	CommonAircraftAmmunition::StartTraveling(aircraftCurrentPosition, destinationPosition);

	// Ammunition traveling animation // 
	auto ammunitionTravelingAction = cocos2d::MoveTo::create(AMMUNITION_TRAVELING_SPEED_AIRCRAFT * (cocos2d::Director::getInstance()->getVisibleSize().height - 160),
		mObjectSprite->getPosition() + (destinationPosition - mObjectSprite->getPosition()).getNormalized() * AIRCRAFT_AMMUNITION_DIRECTION_NORMALIZE_VALUE);

	// Callback for setting back to inactive
	auto callbackFinishedTraveling = cocos2d::CallFunc::create([=]() {
		mIsActive = false;
		mObjectSprite->setVisible(false);
	});

	mObjectSprite->runAction(cocos2d::Sequence::create(ammunitionTravelingAction, callbackFinishedTraveling, nullptr));
}

void AircraftAmmunitionLevel5::StopTraveling()
{
	CommonAircraftAmmunition::StopTraveling();
}

///////////////////////////////////////////////////  AircraftAmmunitionLevel6 ////////////////////////////////////////////////// 

AircraftAmmunitionLevel6::AircraftAmmunitionLevel6(cocos2d::Scene* scene, const int& damageAmount) : CommonAircraftAmmunition(damageAmount)
{
	// The ammunition sprite
	mObjectSprite = cocos2d::Sprite::create("Sprites/Gameplay/Aircrafts Ammunition/Ammunition 6.png");
	scene->addChild(mObjectSprite, 7);
	mObjectSprite->setVisible(false);
}

void AircraftAmmunitionLevel6::StartTraveling(const cocos2d::Vec2& aircraftCurrentPosition, const cocos2d::Vec2& destinationPosition)
{
	CommonAircraftAmmunition::StartTraveling(aircraftCurrentPosition, destinationPosition);

	// Ammunition traveling animation // 
	auto ammunitionTravelingAction = cocos2d::MoveTo::create(AMMUNITION_TRAVELING_SPEED_AIRCRAFT * (cocos2d::Director::getInstance()->getVisibleSize().height - 200),
		mObjectSprite->getPosition() + (destinationPosition - mObjectSprite->getPosition()).getNormalized() * AIRCRAFT_AMMUNITION_DIRECTION_NORMALIZE_VALUE);

	// Callback for setting back to inactive
	auto callbackFinishedTraveling = cocos2d::CallFunc::create([=]() {
		mIsActive = false;
		mObjectSprite->setVisible(false);
	});

	mObjectSprite->runAction(cocos2d::Sequence::create(ammunitionTravelingAction, callbackFinishedTraveling, nullptr));
}

void AircraftAmmunitionLevel6::StopTraveling()
{
	CommonAircraftAmmunition::StopTraveling();
}

///////////////////////////////////////////////////  AircraftAmmunitionLevel7 ////////////////////////////////////////////////// 

AircraftAmmunitionLevel7::AircraftAmmunitionLevel7(cocos2d::Scene* scene, const int& damageAmount) : CommonAircraftAmmunition(damageAmount)
{
	// The ammunition sprite
	mObjectSprite = cocos2d::Sprite::create("Sprites/Gameplay/Aircrafts Ammunition/Ammunition 7.png");
	scene->addChild(mObjectSprite, 7);
	mObjectSprite->setVisible(false);
}

void AircraftAmmunitionLevel7::StartTraveling(const cocos2d::Vec2& aircraftCurrentPosition, const cocos2d::Vec2& destinationPosition)
{
	CommonAircraftAmmunition::StartTraveling(aircraftCurrentPosition, destinationPosition);

	// Ammunition traveling animation // 
	auto ammunitionTravelingAction = cocos2d::MoveTo::create(AMMUNITION_TRAVELING_SPEED_AIRCRAFT * (cocos2d::Director::getInstance()->getVisibleSize().height - 240),
		mObjectSprite->getPosition() + (destinationPosition - mObjectSprite->getPosition()).getNormalized() * AIRCRAFT_AMMUNITION_DIRECTION_NORMALIZE_VALUE);

	// Callback for setting back to inactive
	auto callbackFinishedTraveling = cocos2d::CallFunc::create([=]() {
		mIsActive = false;
		mObjectSprite->setVisible(false);
	});

	mObjectSprite->runAction(cocos2d::Sequence::create(ammunitionTravelingAction, callbackFinishedTraveling, nullptr));
}

void AircraftAmmunitionLevel7::StopTraveling()
{
	CommonAircraftAmmunition::StopTraveling();
}

///////////////////////////////////////////////////  AircraftAmmunitionLevel8 ////////////////////////////////////////////////// 

AircraftAmmunitionLevel8::AircraftAmmunitionLevel8(cocos2d::Scene* scene, const int& damageAmount) : CommonAircraftAmmunition(damageAmount)
{
	// The ammunition sprite
	mObjectSprite = cocos2d::Sprite::create("Sprites/Gameplay/Aircrafts Ammunition/Ammunition 8.png");
	scene->addChild(mObjectSprite, 8);
	mObjectSprite->setVisible(false);
}

void AircraftAmmunitionLevel8::StartTraveling(const cocos2d::Vec2& aircraftCurrentPosition, const cocos2d::Vec2& destinationPosition)
{
	CommonAircraftAmmunition::StartTraveling(aircraftCurrentPosition, destinationPosition);

	// Ammunition traveling animation // 
	auto ammunitionTravelingAction = cocos2d::MoveTo::create(AMMUNITION_TRAVELING_SPEED_AIRCRAFT * (cocos2d::Director::getInstance()->getVisibleSize().height - 280),
		mObjectSprite->getPosition() + (destinationPosition - mObjectSprite->getPosition()).getNormalized() * AIRCRAFT_AMMUNITION_DIRECTION_NORMALIZE_VALUE);

	// Callback for setting back to inactive
	auto callbackFinishedTraveling = cocos2d::CallFunc::create([=]() {
		mIsActive = false;
		mObjectSprite->setVisible(false);
	});

	mObjectSprite->runAction(cocos2d::Sequence::create(ammunitionTravelingAction, callbackFinishedTraveling, nullptr));
}

void AircraftAmmunitionLevel8::StopTraveling()
{
	CommonAircraftAmmunition::StopTraveling();
}