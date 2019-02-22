#include "Enemy.h"
#include "models/ammunition/EnemyAmmunition.h"
#include "common/CommonValues.h"
#include "utils/Utils.h"

#include "SimpleAudioEngine.h"

Enemy::Enemy(cocos2d::Scene* scene, const std::string& spritePath1, const std::string& spritePath2, const int& damageAmount,
	const bool& isAbleToShoot, const int& zOrder, const int& healthMultiplier) : Model(), Shooter(healthMultiplier)
{
	// The flying enemy sprite // 
	mObjectSprite = cocos2d::Sprite::create(spritePath1);
	scene->addChild(mObjectSprite, zOrder);
	mObjectSprite->setVisible(false);

	cocos2d::Vector<cocos2d::SpriteFrame*> animFrames;

	animFrames.pushBack(cocos2d::SpriteFrame::create(spritePath1, cocos2d::Rect(0, 0, mObjectSprite->getContentSize().width, mObjectSprite->getContentSize().height)));
	animFrames.pushBack(cocos2d::SpriteFrame::create(spritePath2, cocos2d::Rect(0, 0, mObjectSprite->getContentSize().width, mObjectSprite->getContentSize().height)));

	// Create the animation out of the frames
	cocos2d::Animation* animation = cocos2d::Animation::createWithSpriteFrames(animFrames, 0.1f);
	// Run it and repeat it forever
	mObjectSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(animation)));

	// The enemy explosion sprite // 
	mEnemyExplosionSprite = cocos2d::Sprite::create();
	scene->addChild(mEnemyExplosionSprite, 6);
	mEnemyExplosionSprite->setVisible(false);

	// Initialize the lists of ammunitions, for each type of enemy initialized with a specified number of default ammunitions for each type //  

	if (damageAmount == ENEMY_DAMAGE_AMOUNT_LEVEL_1)
	{
		for (int i = 0; i < NUMBER_OF_INITIAL_AMMUNITIONS_ENEMY_PER_TYPE; i++)
		{
			mMapOfVectorsOfAmmunitions[1].push_back(new EnemyAmmunitionLevel1(scene, ENEMY_AMMUNITION_DAMAGE_AMOUNT_LEVEL_1));
		}
	}
	else if (damageAmount == ENEMY_DAMAGE_AMOUNT_LEVEL_2)
	{
		for (int i = 0; i < NUMBER_OF_INITIAL_AMMUNITIONS_ENEMY_PER_TYPE; i++)
		{
			mMapOfVectorsOfAmmunitions[1].push_back(new EnemyAmmunitionLevel2(scene, ENEMY_AMMUNITION_DAMAGE_AMOUNT_LEVEL_2));
		}
	}
	else if (damageAmount == ENEMY_DAMAGE_AMOUNT_LEVEL_3)
	{
		for (int i = 0; i < NUMBER_OF_INITIAL_AMMUNITIONS_ENEMY_PER_TYPE; i++)
		{
			mMapOfVectorsOfAmmunitions[1].push_back(new EnemyAmmunitionLevel3(scene, ENEMY_AMMUNITION_DAMAGE_AMOUNT_LEVEL_3));
		}
	}

	// Set up local data //
	mDamageAmount = damageAmount;
	mIsAbleToShoot = isAbleToShoot;
	mHealthMultiplier = healthMultiplier;
}

int Enemy::GetDamageAmount() const
{
	return mDamageAmount;
}

bool Enemy::IsAbleToShoot() const
{
	return mIsAbleToShoot;
}

void Enemy::StartAttacking(cocos2d::Vec2 aircraftCurrentPosition)
{
	mCurrentHealth = MAX_HEALTH * mHealthMultiplier;
	mIsDead = false;
	mIsActive = true;
	mObjectSprite->setVisible(true);

	// This is the craziness of the game //
	auto randomRatio = CCRANDOM_0_1();

	mObjectSprite->setPosition(cocos2d::Director::getInstance()->getVisibleSize().width * randomRatio,
		cocos2d::Director::getInstance()->getVisibleSize().height + ENEMY_HIDING_OFFSET_POSITION);

	// Enemy traveling animation // 
	auto enemyAttackingAction = cocos2d::MoveTo::create(ENEMY_ATTACKING_SPEED * cocos2d::Director::getInstance()->getVisibleSize().height,
		mObjectSprite->getPosition() + (aircraftCurrentPosition - mObjectSprite->getPosition()).getNormalized() * ENEMY_NORMALIZE_VALUE);

	// Callback for setting back to inactive
	auto callbackFinishedTraveling = cocos2d::CallFunc::create([=]() {
		mIsActive = false;
		mObjectSprite->setVisible(false);
	});

	travelingAction = cocos2d::Sequence::create(enemyAttackingAction, callbackFinishedTraveling, nullptr);
	mObjectSprite->runAction(travelingAction);
}

void Enemy::StopAttacking()
{
	// Play sound // 
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Audio/Gameplay/Enemy/Explosion.wav");

	// Stop the traveling action
	if (travelingAction)
		mObjectSprite->stopAction(travelingAction);

	mIsActive = false;
	mObjectSprite->setVisible(false);

	// Create an explosion effect //   

	// Callback to set back to stop animating
	auto callbackFinishedExploding = cocos2d::CallFunc::create([=]() {
		mEnemyExplosionSprite->stopAllActions();
		mEnemyExplosionSprite->setVisible(false);
	});

	// The explosion animation  
	auto explosionAnimationSequence = cocos2d::Sequence::create(cocos2d::Animate::create(
		cocos2d::Animation::createWithSpriteFrames(
			Utils::GetAVectorOfSpriteFramesByCache(
				Utils::GetInitialOfTheExplosionEffect(mDamageAmount),
				Utils::GetTheNumberOfPicturesOfTheExplosionEffect(mDamageAmount)),
			2.0f / Utils::GetTheNumberOfPicturesOfTheExplosionEffect(mDamageAmount)))
		, callbackFinishedExploding, nullptr);

	mEnemyExplosionSprite->setVisible(true);
	mEnemyExplosionSprite->setPosition(this->GetCurrentPosition());
	mEnemyExplosionSprite->runAction(explosionAnimationSequence);
}

void Enemy::Update()
{
	mShootingFrameCount++;

	if (mShootingFrameCount % ENEMY_SHOOTING_FRAME_COUNT == 0)
		Shoot(1, 1, mObjectSprite->getPosition());
}

void Enemy::Shoot(const int& ammunitionIndexKey, const int& shootingGrade, const cocos2d::Vec2& origin) const
{
	for (Ammunition* ammunition : mMapOfVectorsOfAmmunitions.at(ammunitionIndexKey))
	{
		if (!ammunition->IsActive())
		{
			ammunition->StartTraveling(mObjectSprite->getPosition(), cocos2d::Vec2::ZERO);

			break;
		}
	}
}

void Enemy::Damage(int takenHealth)
{
	mCurrentHealth -= takenHealth;

	if (mCurrentHealth <= 0 && !mIsDead)
	{
		mIsDead = true;

		StopAttacking();
	}
}