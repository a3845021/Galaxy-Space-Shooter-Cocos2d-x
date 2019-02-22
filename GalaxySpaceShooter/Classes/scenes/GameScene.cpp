#include "GameScene.h"
#include "common/CommonValues.h"

// Static variables initialization //
int GameScene::sSceneLevelIndex = 0;
int GameScene::sScore = 0;

cocos2d::Scene* GameScene::createScene(const int& levelIndex)
{
	sSceneLevelIndex = levelIndex;

	auto scene = cocos2d::Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene::init()
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

	// The aircraft controller initalization //
	mAircraft = new Aircraft(this, sSceneLevelIndex);

	// The enemy controller initalization //
	mEnemyManagement = new EnemyManagement(this, sSceneLevelIndex);

	// The score label //
	mScoreLable = cocos2d::Label::createWithTTF("0", "Fonts/Arial.ttf", SCORE_TEXT_FONT_SIZE);
	mScoreLable->setPosition(x, visibleSize.height - 40);
	this->addChild(mScoreLable, 5);

	// Called every single frame //
	this->scheduleUpdate();

	return true;
}

void GameScene::update(float dt)
{
	// The background parallaxing //
	mBackground->Update();

	// The flying aircraft update //
	mAircraft->Update();

	// The attacking enemies update //
	mEnemyManagement->Update(mAircraft->GetCurrentPosition());

	// Collision checking between active game objects on the scene //
	CheckCollision();
}

void GameScene::CheckCollision()
{
	// Get a list of enemies being active on the scene
	std::vector<Enemy*> vectorOfActiveEnemies = mEnemyManagement->GetAVectorOfActiveEnemies();

	// Check the position of the aircraft's ammunitions in relation with the enemies
	for (Ammunition* ammunition : mAircraft->GetAVectorOfActiveAmmunitions())
	{
		for (Enemy* enemy : vectorOfActiveEnemies)
		{
			// If there is a collision being occured
			if (ammunition->GetCurrentPosition().getDistance(enemy->GetCurrentPosition()) < COLLISION_MIN_DISTANCE)
			{
				// Stop the ammunition
				ammunition->StopTraveling();

				// Damage the enemy
				enemy->Damage(ammunition->GetDamageAmount());

				// Update the score if this enemy dies
				if (enemy->IsDead())
				{
					sScore += enemy->GetDamageAmount();

					mScoreLable->setString(std::to_string(sScore));
				}

				break;
			}
		}
	}

	// Check the position of the enemies in relation with the aircraft 
	for (Enemy* enemy : vectorOfActiveEnemies)
	{
		if (mAircraft->GetCurrentPosition().getDistance(enemy->GetCurrentPosition()) < COLLISION_MIN_DISTANCE)
		{
			// Damage the aircraft
			mAircraft->Damage(enemy->GetDamageAmount());

			// Hide the enemy, create explosion effect
			enemy->StopAttacking();

			break;
		}
	}

	// Check the position of the enemies' ammunitions in relation with the aircraft
	for (Enemy* enemy : mEnemyManagement->GetAVectorOfEnemies())
	{
		for (Ammunition* ammunition : enemy->GetAVectorOfActiveAmmunitions())
		{
			// If there is a collision being occured
			if (ammunition->GetCurrentPosition().getDistance(mAircraft->GetCurrentPosition()) < COLLISION_MIN_DISTANCE)
			{
				// Stop the ammunition
				ammunition->StopTraveling();

				// Damage the aircraft
				mAircraft->Damage(ammunition->GetDamageAmount());
			}
		}
	}
}
