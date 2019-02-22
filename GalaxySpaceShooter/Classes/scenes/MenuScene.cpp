#include "MenuScene.h" 
#include "scenes/GameScene.h"  
#include "common/CommonValues.h" 
#include "utils/Utils.h"

#include "ui/CocosGUI.h"

cocos2d::Scene* MenuScene::createScene()
{
	auto scene = cocos2d::Scene::create();
	auto layer = MenuScene::create();
	scene->addChild(layer);
	return scene;
}

bool MenuScene::init()
{
	if (!cocos2d::Scene::init())
	{
		return false;
	}

	auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

	float x = origin.x + visibleSize.width / 2;
	float y = origin.y + visibleSize.height / 2;

	// The background initialization // 
	mBackground = new Background(this);

	// The title sprite // 
	auto titleSprite = cocos2d::Sprite::create("Sprites/UI/Title Image.png");
	titleSprite->setPosition(x, visibleSize.height - titleSprite->getContentSize().height / 2);
	this->addChild(titleSprite, 1);

	// The flying aircraft sprite // 
	auto aircraftSprite = cocos2d::Sprite::create("Sprites/Gameplay/Aircrafts/Aircraft 1/Aircraft Anim 1.png");
	aircraftSprite->setPosition(x, titleSprite->getPosition().y - titleSprite->getContentSize().height - aircraftSprite->getContentSize().height / 5);
	this->addChild(aircraftSprite, 2);

	cocos2d::Vector<cocos2d::SpriteFrame*> animFramesAircraft = Utils::GetAVectorOfSpriteFramesByCache("Aircraft Anim %d.png", 26);
	aircraftSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(cocos2d::Animation::createWithSpriteFrames(animFramesAircraft, 0.5f / 26))));

	// The highscore image view //
	auto highscoreImageView = cocos2d::ui::ImageView::create("Sprites/UI/Highscore Icon.png");
	highscoreImageView->setPosition(cocos2d::Vec2(x, aircraftSprite->getPosition().y - aircraftSprite->getContentSize().height));
	this->addChild(highscoreImageView, 3);

	// The highscore label //
	auto highscoreLabel = cocos2d::Label::createWithTTF("0", "Fonts/Arial.ttf", SCORE_HIGHSCORE_FONT_SIZE);
	highscoreLabel->setString(std::to_string(Utils::GetTheBestScore(0)));
	highscoreLabel->setPosition(cocos2d::Vec2(x, highscoreImageView->getPosition().y - highscoreImageView->getContentSize().height));
	this->addChild(highscoreLabel, 4);

	// The planets levels page view // 

	// The planet page view contains the layout nodes
	auto planetPageView = cocos2d::ui::PageView::create();
	planetPageView->setTouchEnabled(true);
	planetPageView->setContentSize(cocos2d::Size(visibleSize.width, LEVEL_PAGE_VIEW_HEIGHT));
	planetPageView->setPosition(cocos2d::Vec2(0, 0));
	this->addChild(planetPageView, 5);

	char normalStateStr[100];
	char clickStateStr[100];

	// Add layout nodes the the planet page view
	for (int i = 1; i <= NUMBER_OF_LEVELS; i++)
	{
		sprintf(normalStateStr, "Sprites/Gameplay/Planets/Planet %d Normal.png", i);
		sprintf(clickStateStr, "Sprites/Gameplay/Planets/Planet %d Click.png", i);

		// The planet button  
		auto planetButton = cocos2d::ui::Button::create(normalStateStr, clickStateStr, normalStateStr);
		planetButton->setPosition(cocos2d::Vec2(x, y - highscoreImageView->getContentSize().height - planetButton->getContentSize().height / 2));

		planetButton->addTouchEventListener([=](Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
			switch (type)
			{
			case cocos2d::ui::Widget::TouchEventType::ENDED:
				MenuScene::GoToGameScene((int)planetPageView->getCurSelectedIndex());
				break;
			default:
				break;
			}
		});

		// The planet name label
		auto planetNameLabel = cocos2d::Label::createWithTTF(Utils::GetPlanetNameBasedOnTheIndex(i - 1), "Fonts/Arial.ttf", PLANET_NAME_FONT_SIZE);
		planetNameLabel->setPosition(x, planetButton->getPosition().y - planetButton->getContentSize().height / 2 - planetNameLabel->getContentSize().height);

		// Planet name animation
		auto planetNameAnimationScaleToStart = cocos2d::ScaleTo::create(0.5f, 1.1f);
		auto planetNameAnimationScaleToEnd = cocos2d::ScaleTo::create(0.5f, 1);
		planetNameLabel->runAction(cocos2d::RepeatForever::create(cocos2d::Sequence::create(planetNameAnimationScaleToStart, planetNameAnimationScaleToEnd, nullptr)));

		// The planet description lable
		auto planetDescriptionLabel = cocos2d::Label::createWithTTF(Utils::GetPlanetDescriptionBasedOnTheIndex(i - 1), "Fonts/Arial.ttf", PLANET_DESCRIPTION_FONT_SIZE);
		planetDescriptionLabel->setPosition(x, planetNameLabel->getPosition().y - planetNameLabel->getContentSize().height / 2 - planetDescriptionLabel->getContentSize().height);

		// The planet layout contains the child nodes
		auto planetLayout = cocos2d::ui::Layout::create();
		planetLayout->setPosition(cocos2d::Vec2(0, 0));
		planetLayout->setContentSize(cocos2d::Size(visibleSize.width, LEVEL_PAGE_VIEW_HEIGHT));

		planetLayout->addChild(planetButton);
		planetLayout->addChild(planetNameLabel);
		planetLayout->addChild(planetDescriptionLabel);

		planetPageView->addPage(planetLayout);
	}

	// The background changing button: Invisible! //
	auto changeBackgroundButton = cocos2d::ui::Button::create("Sprites/UI/Change Background Button.png", "Sprites/UI/Change Background Button.png", "Sprites/UI/Change Background Button.png");
	changeBackgroundButton->setPosition(cocos2d::Vec2(visibleSize.width - changeBackgroundButton->getContentSize().width / 2, changeBackgroundButton->getContentSize().height / 2));
	this->addChild(changeBackgroundButton, 6);

	changeBackgroundButton->addTouchEventListener([=](Ref* sender, cocos2d::ui::Widget::TouchEventType type) {
		switch (type)
		{
		case cocos2d::ui::Widget::TouchEventType::ENDED:
			Utils::ChangeTheBackgroundIndex();
			mBackground->ChangeBackground();
			break;
		default:
			break;
		}
	}); 

	// Called every single frame //
	this->scheduleUpdate();

	return true;
}

void MenuScene::update(float dt)
{
	mBackground->Update();
}

void MenuScene::GoToGameScene(const int& levelIndex)
{
	auto scene = GameScene::createScene(levelIndex);
	cocos2d::Director::getInstance()->replaceScene(cocos2d::TransitionFade::create(SCENE_TRANSITION_TIME, scene));
}
