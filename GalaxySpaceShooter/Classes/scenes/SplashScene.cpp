#include "SplashScene.h"
#include "scenes/MenuScene.h"
#include "common/CommonValues.h"

#include "SimpleAudioEngine.h"
 
cocos2d::Scene* SplashScene::createScene()
{
	auto scene = cocos2d::Scene::create();
	auto layer = SplashScene::create();
	scene->addChild(layer);
	return scene;
}

bool SplashScene::init()
{
	if (!cocos2d::Scene::init())
	{
		return false;
	}

	// Populate plish sources // 
	cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Sprites/Gameplay/Aircrafts/Aircraft 1/Aircraft.plist");
	cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Sprites/Gameplay/Enemies Damage/Damage 1/Explosion Level 1.plist");
	cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Sprites/Gameplay/Enemies Damage/Damage 2/Explosion Level 2.plist");
	cocos2d::SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Sprites/Gameplay/Enemies Damage/Damage 3/Explosion Level 3.plist");
	 
	// Populate audio sources // 
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Audio/Gameplay/Background/Background.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Audio/Gameplay/Aircraft/Explosion.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Audio/Gameplay/Enemy/Explosion.wav");
	 
	// Play background sound //
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Audio/Gameplay/Background/Background.wav", true);

	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	float x = origin.x + visibleSize.width / 2;
	float y = origin.y + visibleSize.height / 2;

	// The background splash screen sprite // 
	auto splashScreenSprite = cocos2d::Sprite::create("Sprites/UI/Splash Image.png");
	splashScreenSprite->setPosition(x, y);
	this->addChild(splashScreenSprite, 0);

	// Called only once to go to the menu scene after a specified duration of time //
	this->scheduleOnce(schedule_selector(SplashScene::GoToMenuScene), SCENE_OPENING_DELAY_TIME);
	  
	return true;
}

void SplashScene::GoToMenuScene(float dt)
{
	auto scene = MenuScene::createScene();
	cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(SCENE_TRANSITION_TIME, scene));
}