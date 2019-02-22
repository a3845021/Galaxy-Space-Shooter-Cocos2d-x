#include "Background.h" 
#include "common/CommonValues.h"
#include "utils/Utils.h"

Background::Background(cocos2d::Scene* scene)
{
	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

	if (Utils::GetTheBackgroundIndex() == 0)
	{
		mBackgroundSprite_1 = cocos2d::Sprite::create("Sprites/Gameplay/Background/Grade 1.png");
		mBackgroundSprite_2 = cocos2d::Sprite::create("Sprites/Gameplay/Background/Grade 1.png");
	}
	else
	{
		mBackgroundSprite_1 = cocos2d::Sprite::create("Sprites/Gameplay/Background/Grade 2.png");
		mBackgroundSprite_2 = cocos2d::Sprite::create("Sprites/Gameplay/Background/Grade 2.png");
	}

	mBackgroundSprite_1->setAnchorPoint(cocos2d::Point(0, 0));
	mBackgroundSprite_1->setPosition(cocos2d::Point(0, 0));
	scene->addChild(mBackgroundSprite_1, 0);

	mBackgroundSprite_2->setAnchorPoint(cocos2d::Point(0, 0));
	mBackgroundSprite_2->setPosition(cocos2d::Point(0, visibleSize.height));
	scene->addChild(mBackgroundSprite_2, 0);

	mBackgroundStarsSprite_1 = cocos2d::Sprite::create("Sprites/Gameplay/Background/Stars.png");
	mBackgroundStarsSprite_1->setAnchorPoint(cocos2d::Point(0, 0));
	mBackgroundStarsSprite_1->setPosition(cocos2d::Point(0, 0));
	scene->addChild(mBackgroundStarsSprite_1, 1);

	mBackgroundStarsSprite_2 = cocos2d::Sprite::create("Sprites/Gameplay/Background/Stars.png");
	mBackgroundStarsSprite_2->setAnchorPoint(cocos2d::Point(0, 0));
	mBackgroundStarsSprite_2->setPosition(cocos2d::Point(0, visibleSize.height));
	scene->addChild(mBackgroundStarsSprite_2, 1);

	auto backgroundSlidingAction = cocos2d::RepeatForever::create(cocos2d::MoveBy::create(BACKGROUND_SLIDING_DURATION_TIME, cocos2d::Vec2(0, -visibleSize.height)));
	auto backgroundStarsSlidingAction = cocos2d::RepeatForever::create(cocos2d::MoveBy::create(BACKGROUND_STARS_SLIDING_DURATION_TIME, cocos2d::Vec2(0, -visibleSize.height)));

	mBackgroundSprite_1->runAction(backgroundSlidingAction);
	mBackgroundSprite_2->runAction(backgroundSlidingAction->clone());
	mBackgroundStarsSprite_1->runAction(backgroundStarsSlidingAction);
	mBackgroundStarsSprite_2->runAction(backgroundStarsSlidingAction->clone());
}

void Background::Update()
{
	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

	if (mBackgroundSprite_1->getPosition().y <= -visibleSize.height)
		mBackgroundSprite_1->setPosition(cocos2d::Point(0, 0));

	if (mBackgroundSprite_2->getPosition().y <= 0)
		mBackgroundSprite_2->setPosition(cocos2d::Point(0, visibleSize.height));

	if (mBackgroundStarsSprite_1->getPosition().y <= -visibleSize.height)
		mBackgroundStarsSprite_1->setPosition(cocos2d::Point(0, 0));

	if (mBackgroundStarsSprite_2->getPosition().y <= 0)
		mBackgroundStarsSprite_2->setPosition(cocos2d::Point(0, visibleSize.height));
}

void Background::ChangeBackground()
{
	if (Utils::GetTheBackgroundIndex() == 0)
	{
		mBackgroundSprite_1->setSpriteFrame(cocos2d::SpriteFrame::create("Sprites/Gameplay/Background/Grade 1.png",
			cocos2d::Rect(0, 0, mBackgroundSprite_1->getContentSize().width, mBackgroundSprite_1->getContentSize().height)));
		mBackgroundSprite_2->setSpriteFrame(cocos2d::SpriteFrame::create("Sprites/Gameplay/Background/Grade 1.png",
			cocos2d::Rect(0, 0, mBackgroundSprite_2->getContentSize().width, mBackgroundSprite_2->getContentSize().height)));
	}
	else
	{
		mBackgroundSprite_1->setSpriteFrame(cocos2d::SpriteFrame::create("Sprites/Gameplay/Background/Grade 2.png",
			cocos2d::Rect(0, 0, mBackgroundSprite_1->getContentSize().width, mBackgroundSprite_1->getContentSize().height)));
		mBackgroundSprite_2->setSpriteFrame(cocos2d::SpriteFrame::create("Sprites/Gameplay/Background/Grade 2.png",
			cocos2d::Rect(0, 0, mBackgroundSprite_2->getContentSize().width, mBackgroundSprite_2->getContentSize().height)));
	}
}