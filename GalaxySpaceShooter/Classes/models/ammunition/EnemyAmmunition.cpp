#include "EnemyAmmunition.h"   
#include "common/CommonValues.h" 

///////////////////////////////////////////////////////// Base class /////////////////////////////////////////////////////////

CommonEnemyAmmunition::CommonEnemyAmmunition(const int& damageAmount) : Ammunition(damageAmount)
{
	// Constructor  
}

void CommonEnemyAmmunition::StartTraveling(const cocos2d::Vec2& enemyCurrentPosition, const cocos2d::Vec2& destinationPosition)
{
	mIsActive = true;
	mObjectSprite->setVisible(true);

	// Set the departing position
	mObjectSprite->setPosition(enemyCurrentPosition.x, enemyCurrentPosition.y - AMMUNITION_POSITION_OFFSET_ENEMY);
}

void CommonEnemyAmmunition::StopTraveling()
{
	// Stop all the action that has attached to this
	mObjectSprite->stopAllActions();

	mIsActive = false;
	mObjectSprite->setVisible(false);
}

///////////////////////////////////////////////////////// Drived class /////////////////////////////////////////////////////////

///////////////////////////////////////////////////  EnemyAmmunitionLevel1 ////////////////////////////////////////////////// 

EnemyAmmunitionLevel1::EnemyAmmunitionLevel1(cocos2d::Scene* scene, const int& damageAmount) : CommonEnemyAmmunition(damageAmount)
{
	// The ammunition sprite
	mObjectSprite = cocos2d::Sprite::create("Sprites/Gameplay/Enemies Ammunition/Ammunition 1.png");
	scene->addChild(mObjectSprite, 2);
	mObjectSprite->setVisible(false);
}

void EnemyAmmunitionLevel1::StartTraveling(const cocos2d::Vec2& enemyCurrentPosition, const cocos2d::Vec2& destinationPosition)
{
	CommonEnemyAmmunition::StartTraveling(enemyCurrentPosition, destinationPosition);

	// Ammunition traveling animation // 
	auto ammunitionTravelingAction = cocos2d::MoveBy::create(AMMUNITION_TRAVELING_SPEED_ENEMY * (cocos2d::Director::getInstance()->getVisibleSize().height - 100),
		cocos2d::Vec2(0, -cocos2d::Director::getInstance()->getVisibleSize().height - ENEMY_HIDING_OFFSET_POSITION));

	// Callback for setting back to inactive
	auto callbackFinishedTraveling = cocos2d::CallFunc::create([=]() {
		mIsActive = false;
		mObjectSprite->setVisible(false);
	});

	mObjectSprite->runAction(cocos2d::Sequence::create(ammunitionTravelingAction, callbackFinishedTraveling, nullptr));
}

void EnemyAmmunitionLevel1::StopTraveling()
{
	CommonEnemyAmmunition::StopTraveling();
}

///////////////////////////////////////////////////  EnemyAmmunitionLevel2 ////////////////////////////////////////////////// 

EnemyAmmunitionLevel2::EnemyAmmunitionLevel2(cocos2d::Scene* scene, const int& damageAmount) : CommonEnemyAmmunition(damageAmount)
{
	// The ammunition sprite
	mObjectSprite = cocos2d::Sprite::create("Sprites/Gameplay/Enemies Ammunition/Ammunition 2.png");
	scene->addChild(mObjectSprite, 3);
	mObjectSprite->setVisible(false);
}

void EnemyAmmunitionLevel2::StartTraveling(const cocos2d::Vec2& enemyCurrentPosition, const cocos2d::Vec2& destinationPosition)
{
	CommonEnemyAmmunition::StartTraveling(enemyCurrentPosition, destinationPosition);

	// Ammunition traveling animation // 
	auto ammunitionTravelingAction = cocos2d::MoveBy::create(AMMUNITION_TRAVELING_SPEED_ENEMY  * (cocos2d::Director::getInstance()->getVisibleSize().height - 200),
		cocos2d::Vec2(0, -cocos2d::Director::getInstance()->getVisibleSize().height - ENEMY_HIDING_OFFSET_POSITION));

	// Callback for setting back to inactive
	auto callbackFinishedTraveling = cocos2d::CallFunc::create([=]() {
		mIsActive = false;
		mObjectSprite->setVisible(false);
	});

	mObjectSprite->runAction(cocos2d::Sequence::create(ammunitionTravelingAction, callbackFinishedTraveling, nullptr));
}

void EnemyAmmunitionLevel2::StopTraveling()
{
	CommonEnemyAmmunition::StopTraveling();
}

///////////////////////////////////////////////////  EnemyAmmunitionLevel3 ////////////////////////////////////////////////// 

EnemyAmmunitionLevel3::EnemyAmmunitionLevel3(cocos2d::Scene* scene, const int& damageAmount) : CommonEnemyAmmunition(damageAmount)
{
	// The ammunition sprite
	mObjectSprite = cocos2d::Sprite::create("Sprites/Gameplay/Enemies Ammunition/Ammunition 3.png");
	scene->addChild(mObjectSprite, 4);
	mObjectSprite->setVisible(false);
}

void EnemyAmmunitionLevel3::StartTraveling(const cocos2d::Vec2& enemyCurrentPosition, const cocos2d::Vec2& destinationPosition)
{
	CommonEnemyAmmunition::StartTraveling(enemyCurrentPosition, destinationPosition);

	// Ammunition traveling animation // 
	auto ammunitionTravelingAction = cocos2d::MoveBy::create(AMMUNITION_TRAVELING_SPEED_ENEMY  * (cocos2d::Director::getInstance()->getVisibleSize().height - 300),
		cocos2d::Vec2(0, -cocos2d::Director::getInstance()->getVisibleSize().height - ENEMY_HIDING_OFFSET_POSITION));

	// Callback for setting back to inactive
	auto callbackFinishedTraveling = cocos2d::CallFunc::create([=]() {
		mIsActive = false;
		mObjectSprite->setVisible(false);
	});

	mObjectSprite->runAction(cocos2d::Sequence::create(ammunitionTravelingAction, callbackFinishedTraveling, nullptr));
}

void EnemyAmmunitionLevel3::StopTraveling()
{
	CommonEnemyAmmunition::StopTraveling();
}