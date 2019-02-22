#include "Aircraft.h"
#include "models/ammunition/AircraftAmmunition.h"
#include "common/CommonValues.h"
#include "utils/Utils.h"
#include "scenes/GameOverScene.h"

#include "SimpleAudioEngine.h"
 
Aircraft::Aircraft(cocos2d::Scene* scene, const int& sceneLevelIndex) : Model(), Shooter(1)
{
	cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	cocos2d::Vec2 sceneCenterPosition(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2);

	// The flying aircraft sprite // 
	mObjectSprite = cocos2d::Sprite::create("Sprites/Gameplay/Aircrafts/Aircraft 1/Aircraft Anim 1.png");
	mObjectSprite->setPosition(sceneCenterPosition);
	scene->addChild(mObjectSprite, 3);

	cocos2d::Vector<cocos2d::SpriteFrame*> animFramesAircraft = Utils::GetAVectorOfSpriteFramesByCache("Aircraft Anim %d.png", 26);
	mObjectSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(cocos2d::Animation::createWithSpriteFrames(animFramesAircraft, 0.5f / 26))));

	// The damaging sprite // 
	mDamagedSprite = cocos2d::Sprite::create("Sprites/Gameplay/Aircrafts Damage/Damage.png");
	mDamagedSprite->setPosition(sceneCenterPosition);
	mDamagedSprite->setVisible(false);
	scene->addChild(mDamagedSprite, 4);

	// The dragging controller of the aircraft  // 
	auto touchListener = cocos2d::EventListenerTouchOneByOne::create();
	touchListener->setSwallowTouches(true); 
	touchListener->onTouchBegan = CC_CALLBACK_2(Aircraft::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(Aircraft::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(Aircraft::onTouchEnded, this); 
	scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, scene);

	// Initialize the lists of ammunitions, for each type initialized with a specified number of default ammunitions for each type //
	for (int i = 1; i <= NUMBER_OF_AMMUNITION_TYPES_AIRCRAFT; i++)
	{
		std::vector<Ammunition*> vectorOfAmmunitions;

		for (int j = 0; j < NUMBER_OF_INITIAL_AMMUNITIONS_AIRCRAFT_PER_TYPE; j++)
		{
			if (i == 1)
				vectorOfAmmunitions.push_back(new AircraftAmmunitionLevel1(scene, 50));
			else if (i == 2)
				vectorOfAmmunitions.push_back(new AircraftAmmunitionLevel2(scene, 70));
			else if (i == 3)
				vectorOfAmmunitions.push_back(new AircraftAmmunitionLevel3(scene, 90));
			else if (i == 4)
				vectorOfAmmunitions.push_back(new AircraftAmmunitionLevel4(scene, 110));
			else if (i == 5)
				vectorOfAmmunitions.push_back(new AircraftAmmunitionLevel5(scene, 130));
			else if (i == 6)
				vectorOfAmmunitions.push_back(new AircraftAmmunitionLevel6(scene, 150));
			else if (i == 7)
				vectorOfAmmunitions.push_back(new AircraftAmmunitionLevel7(scene, 170));
			else
				vectorOfAmmunitions.push_back(new AircraftAmmunitionLevel8(scene, 190));
		}

		mMapOfVectorsOfAmmunitions[i] = vectorOfAmmunitions;
	}

	// The health bar // 
	mHealthBar = cocos2d::ui::LoadingBar::create("Sprites/UI/Health Bar Image.png");
	mHealthBar->setPosition(cocos2d::Vec2(sceneCenterPosition.x, 0 + mHealthBar->getContentSize().height / 2));
	scene->addChild(mHealthBar, 5);

	mHealthBar->setDirection(cocos2d::ui::LoadingBar::Direction::LEFT);
	mHealthBar->setPercent(mCurrentHealth);

	// Set touch state //
	mIsTouching = false;

	// The shooting controller, based on the scene level index //
	SetupLevel(sceneLevelIndex);
}

void Aircraft::SetupLevel(const int& sceneLevelIndex)
{ 
	switch (sceneLevelIndex)
	{
	case 0:
		mAmmunitionIndexKey = 1;
		mShootingGrade = 3;
		break;
	case 1:
		mAmmunitionIndexKey = 2;
		mShootingGrade = 3;
		break;
	case 2:
		mAmmunitionIndexKey = 3;
		mShootingGrade = 3;
		break;
	case 3:
		mAmmunitionIndexKey = 4;
		mShootingGrade = 3;
		break;
	case 4:
		mAmmunitionIndexKey = 5;
		mShootingGrade = 3;
		break;
	case 5:
		mAmmunitionIndexKey = 6;
		mShootingGrade = 2;
		break;
	case 6:
		mAmmunitionIndexKey = 6;
		mShootingGrade = 3;
		break;
	case 7:
		mAmmunitionIndexKey = 7;
		mShootingGrade = 2;
		break;
	case 8:
		mAmmunitionIndexKey = 7;
		mShootingGrade = 3;
		break;
	case 9:
		mAmmunitionIndexKey = 8;
		mShootingGrade = 3;
		break;  
	}
}

bool Aircraft::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	mIsTouching = true;

	mTouchOffsetPosition = touch->getLocation() - mObjectSprite->getPosition();

	return true;
}

bool Aircraft::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
	mObjectSprite->setPosition(touch->getLocation() - mTouchOffsetPosition);

	return true;
}

bool Aircraft::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	mIsTouching = false;

	return true;
}

void Aircraft::Update()
{
	mShootingFrameCount++;

	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

	// Check the dragging of the aircraft whether or not is in bound //
	if (mObjectSprite->getPosition().x >= visibleSize.width)
		mObjectSprite->setPositionX(visibleSize.width);
	else if (mObjectSprite->getPosition().x <= 0)
		mObjectSprite->setPositionX(0);
	if (mObjectSprite->getPosition().y >= visibleSize.height)
		mObjectSprite->setPositionY(visibleSize.height);
	else if (mObjectSprite->getPosition().y <= 0)
		mObjectSprite->setPositionY(0);

	// Shooting behavior: only shoot when touching the screen
	if (mIsTouching && mShootingFrameCount % AIRCRAFT_SHOOTING_FRAME_COUNT == 0)
	{  
		Shoot(mAmmunitionIndexKey, mShootingGrade, mObjectSprite->getPosition());
	} 
}

void Aircraft::Shoot(const int& ammunitionIndexKey, const int& shootingGrade, const cocos2d::Vec2& origin) const
{
	std::vector<Ammunition*> vectorOfAmmunition = mMapOfVectorsOfAmmunitions.at(ammunitionIndexKey);

	// Store the number of ammunitions per time according to the shooting grade //
	std::vector<Ammunition*> temp;

	int i = 0;

	while (i < vectorOfAmmunition.size())
	{
		if (!vectorOfAmmunition[i]->IsActive())
		{
			if (shootingGrade == 1)
			{
				temp.push_back(vectorOfAmmunition[i]);

				break;
			}

			else if (shootingGrade == 2)
			{
				temp.push_back(vectorOfAmmunition[i]);

				i++;

				while (i < vectorOfAmmunition.size())
				{
					if (!vectorOfAmmunition[i]->IsActive())
					{
						temp.push_back(vectorOfAmmunition[i]);

						break;
					}

					i++;
				}

				break;
			}

			else if (shootingGrade == 3)
			{
				temp.push_back(vectorOfAmmunition[i]);

				i++;

				while (i < vectorOfAmmunition.size())
				{
					if (!vectorOfAmmunition[i]->IsActive())
					{
						temp.push_back(vectorOfAmmunition[i]);

						i++;

						while (i < vectorOfAmmunition.size())
						{
							if (!vectorOfAmmunition[i]->IsActive())
							{
								temp.push_back(vectorOfAmmunition[i]);

								break;
							}

							i++;
						}

						break;
					}

					i++;
				}

				break;
			}
		}

		i++;
	}

	if (temp.size() == 1)
	{
		temp[0]->StartTraveling(origin, cocos2d::Vec2(origin.x, cocos2d::Director::getInstance()->getVisibleSize().height));
	}
	else if (temp.size() == 2)
	{
		temp[0]->StartTraveling(origin, cocos2d::Vec2(origin.x - DISTANCE_BETWEEN_AMMUNITIONS_LEVEL_2, cocos2d::Director::getInstance()->getVisibleSize().height + AMMUNITION_DISTANCE_OFFSET_AIRCRAFT_HEAD));
		temp[1]->StartTraveling(origin, cocos2d::Vec2(origin.x + DISTANCE_BETWEEN_AMMUNITIONS_LEVEL_2, cocos2d::Director::getInstance()->getVisibleSize().height + AMMUNITION_DISTANCE_OFFSET_AIRCRAFT_HEAD));
	}
	else if (temp.size() == 3)
	{
		temp[0]->StartTraveling(origin, cocos2d::Vec2(origin.x - DISTANCE_BETWEEN_AMMUNITIONS_LEVEL_3, cocos2d::Director::getInstance()->getVisibleSize().height + AMMUNITION_DISTANCE_OFFSET_AIRCRAFT_HEAD));
		temp[1]->StartTraveling(origin, cocos2d::Vec2(origin.x, cocos2d::Director::getInstance()->getVisibleSize().height + AMMUNITION_DISTANCE_OFFSET_AIRCRAFT_HEAD));
		temp[2]->StartTraveling(origin, cocos2d::Vec2(origin.x + DISTANCE_BETWEEN_AMMUNITIONS_LEVEL_3, cocos2d::Director::getInstance()->getVisibleSize().height + AMMUNITION_DISTANCE_OFFSET_AIRCRAFT_HEAD));
	}
}

void Aircraft::Damage(int takenHealth)
{
	// Create damage effect //

	// Stop all the previous actions
	mDamagedSprite->stopAllActions();

	// Callback after fading
	auto callbackFinishedFadingin = cocos2d::CallFunc::create([=]() {
		mDamagedSprite->stopAllActions();
		mDamagedSprite->setVisible(false);
	});

	// Fade actions 
	auto fadeIn = cocos2d::FadeIn::create(AIRCRAFT_ATTACKED_STATE_FADE_TIME);
	auto fadeOut = cocos2d::FadeOut::create(AIRCRAFT_ATTACKED_STATE_FADE_TIME);

	// Random flip the sprite
	mDamagedSprite->setFlippedX(CCRANDOM_0_1() > 0.5f ? true : false);
	mDamagedSprite->setFlippedY(CCRANDOM_0_1() > 0.5f ? true : false);

	// Show it and run the action
	mDamagedSprite->setVisible(true);
	mDamagedSprite->runAction(cocos2d::Sequence::create(fadeIn, fadeOut, callbackFinishedFadingin, nullptr));

	// Health deduction //
	mCurrentHealth -= takenHealth;

	// Update the health bar
	mHealthBar->setPercent(mCurrentHealth);

	if (mCurrentHealth <= 0 && !mIsDead)
	{
		mIsDead = true;

		// Play sound //
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Gameplay/Aircraft/Explosion.wav"); 

		// Open the game over scene //
		auto scene = GameOverScene::createScene();
		cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(SCENE_TRANSITION_TIME, scene));
	}
}