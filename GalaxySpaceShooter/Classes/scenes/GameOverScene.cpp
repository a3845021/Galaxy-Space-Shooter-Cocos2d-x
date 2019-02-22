#include "GameOverScene.h"
#include "scenes/GameScene.h"
#include "scenes/MenuScene.h"
#include "common/CommonValues.h"
#include "utils/Utils.h"

cocos2d::Scene* GameOverScene::createScene()
{
	auto scene = Scene::create();
	auto layer = GameOverScene::create();
	scene->addChild(layer);
	return scene;
}

bool GameOverScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	float x = origin.x + visibleSize.width / 2;
	float y = origin.y + visibleSize.height / 2;

	// The background initialization // 
	mBackground = new Background(this);

	// The score image view //
	auto scoreImageView = cocos2d::ui::ImageView::create("Sprites/UI/Score Icon.png");
	scoreImageView->setPosition(cocos2d::Vec2(x, visibleSize.height - scoreImageView->getContentSize().height * 2));
	this->addChild(scoreImageView, 1);

	// The score label //
	auto scoreLabel = cocos2d::Label::createWithTTF("0", "Fonts/Arial.ttf", SCORE_HIGHSCORE_FONT_SIZE);
	scoreLabel->setString(std::to_string(GameScene::sScore));
	scoreLabel->setPosition(cocos2d::Vec2(x, scoreImageView->getPosition().y - scoreImageView->getContentSize().height));
	this->addChild(scoreLabel, 1);

	// The flying aircraft sprite // 
	auto aircraftSprite = cocos2d::Sprite::create("Sprites/Gameplay/Aircrafts/Aircraft 1/Aircraft Anim 1.png");
	aircraftSprite->setPosition(x, scoreLabel->getPositionY() - scoreLabel->getContentSize().height - aircraftSprite->getContentSize().height / 2);
	this->addChild(aircraftSprite, 1);

	cocos2d::Vector<cocos2d::SpriteFrame*> animFramesAircraft = Utils::GetAVectorOfSpriteFramesByCache("Aircraft Anim %d.png", 26);
	aircraftSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(cocos2d::Animation::createWithSpriteFrames(animFramesAircraft, 0.5f / 26))));

	// The highscore image view //
	auto highscoreImageView = cocos2d::ui::ImageView::create("Sprites/UI/Highscore Icon.png");
	highscoreImageView->setPosition(cocos2d::Vec2(x, aircraftSprite->getPositionY() - aircraftSprite->getContentSize().height / 2 - highscoreImageView->getContentSize().height));
	this->addChild(highscoreImageView, 1);

	// The highscore label //
	auto highscoreLabel = cocos2d::Label::createWithTTF("0", "Fonts/Arial.ttf", SCORE_HIGHSCORE_FONT_SIZE);
	highscoreLabel->setString(std::to_string(Utils::GetTheBestScore(GameScene::sScore)));
	highscoreLabel->setPosition(cocos2d::Vec2(x, highscoreImageView->getPosition().y - highscoreImageView->getContentSize().height));
	this->addChild(highscoreLabel, 1);

	// The menu selection //

	// The replay button
	auto replayMenuItemImage = cocos2d::MenuItemImage::create("Sprites/UI/Button Image.png", "Sprites/UI/Button Image Click.png", CC_CALLBACK_1(GameOverScene::PlayAgain, this));
	replayMenuItemImage->setPosition(cocos2d::Vec2(x, highscoreLabel->getPositionY() - highscoreLabel->getContentSize().height * 4));
	auto replayLabel = cocos2d::Label::createWithTTF("Replay", "Fonts/Arial.ttf", BUTTON_LABEL_FONT_SIZE);
	replayLabel->setPosition(cocos2d::Vec2(replayMenuItemImage->getContentSize().width / 2, replayMenuItemImage->getContentSize().height / 2));
	replayMenuItemImage->addChild(replayLabel);

	// The menu button
	auto menuMenuItemImage = cocos2d::MenuItemImage::create("Sprites/UI/Button Image.png", "Sprites/UI/Button Image Click.png", CC_CALLBACK_1(GameOverScene::GoToMenuScene, this));
	menuMenuItemImage->setPosition(cocos2d::Vec2(x, replayMenuItemImage->getPositionY() - replayMenuItemImage->getContentSize().height - menuMenuItemImage->getContentSize().height / 2));
	auto menuLabel = cocos2d::Label::createWithTTF("Menu", "Fonts/Arial.ttf", BUTTON_LABEL_FONT_SIZE);
	menuLabel->setPosition(cocos2d::Vec2(menuMenuItemImage->getContentSize().width / 2, menuMenuItemImage->getContentSize().height / 2));
	menuMenuItemImage->addChild(menuLabel);

	// The menu contains the two above buttons
	auto menu = cocos2d::Menu::create(replayMenuItemImage, menuMenuItemImage, NULL);
	menu->setPosition(cocos2d::Point(0, 0));

	this->addChild(menu, 1);

	// Called every single frame //
	this->scheduleUpdate();

	return true;
}

void GameOverScene::update(float dt)
{
	mBackground->Update();
}

void GameOverScene::PlayAgain(cocos2d::Ref* pSender)
{
	GameScene::sScore = 0;

	auto scene = GameScene::createScene(GameScene::sSceneLevelIndex);
	cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(SCENE_TRANSITION_TIME, scene));
}

void GameOverScene::GoToMenuScene(cocos2d::Ref* pSender)
{
	GameScene::sScore = 0;

	auto scene = MenuScene::createScene();
	cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(SCENE_TRANSITION_TIME, scene));
}