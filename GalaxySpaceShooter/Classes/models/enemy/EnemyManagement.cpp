#include "EnemyManagement.h"
#include "common/CommonValues.h"
 
EnemyManagement::EnemyManagement(cocos2d::Scene* scene, const int& sceneLevelIndex)
{
	mSceneLevelIndex = sceneLevelIndex;

	// Initialize a list of enemies with a specified number of default enemies //
	for (int i = 0; i < NUMBER_OF_INITIAL_ENEMIES_PER_TYPE; i++)
	{
		mVectorOfEnemies.push_back(new Enemy(scene, "Sprites/Gameplay/Enemies/Enemy Level 0-0.png",
			"Sprites/Gameplay/Enemies/Enemy Level 0-0 Animate.png", ENEMY_DAMAGE_AMOUNT_LEVEL_0, false, 5, 1));

		mVectorOfEnemies.push_back(new Enemy(scene, "Sprites/Gameplay/Enemies/Enemy Level 0-1.png",
			"Sprites/Gameplay/Enemies/Enemy Level 0-1 Animate.png", ENEMY_DAMAGE_AMOUNT_LEVEL_0, false, 5, 1));

		mVectorOfEnemies.push_back(new Enemy(scene, "Sprites/Gameplay/Enemies/Enemy Level 0-2.png",
			"Sprites/Gameplay/Enemies/Enemy Level 0-2 Animate.png", ENEMY_DAMAGE_AMOUNT_LEVEL_0, false, 5, 1));

		mVectorOfEnemies.push_back(new Enemy(scene, "Sprites/Gameplay/Enemies/Enemy Level 1.png",
			"Sprites/Gameplay/Enemies/Enemy Level 1 Animate.png", ENEMY_DAMAGE_AMOUNT_LEVEL_1, true, 6, 2));

		mVectorOfEnemies.push_back(new Enemy(scene, "Sprites/Gameplay/Enemies/Enemy Level 2.png",
			"Sprites/Gameplay/Enemies/Enemy Level 2 Animate.png", ENEMY_DAMAGE_AMOUNT_LEVEL_2, true, 7, 3));

		mVectorOfEnemies.push_back(new Enemy(scene, "Sprites/Gameplay/Enemies/Enemy Level 3.png",
			"Sprites/Gameplay/Enemies/Enemy Level 3 Animate.png", ENEMY_DAMAGE_AMOUNT_LEVEL_3, true, 8, 4));
	}
}

void EnemyManagement::Update(const cocos2d::Vec2& aircraftPosition)
{
	mReleasingFrameCount++;

	if (mReleasingFrameCount % (ENEMY_RELEASE_FRAME_COUNT - mSceneLevelIndex) == 0)
	{
		ReleaseAnEnemy(aircraftPosition);
	}

	for (Enemy* enemy : GetAVectorOfActiveEnemies())
	{
		if (enemy->IsActive() && enemy->IsAbleToShoot())
		{
			enemy->Update();
		}
	}
}

void EnemyManagement::ReleaseAnEnemy(const cocos2d::Vec2& aircraftCurrentPosition) const
{
	std::vector<Enemy*> mVectorOfInactiveEnemies;

	for (Enemy* enemy : mVectorOfEnemies)
	{
		if (!enemy->IsActive())
		{
			mVectorOfInactiveEnemies.push_back(enemy);
		}
	}

	int size = mVectorOfInactiveEnemies.size();
	if (size == 0)
		return;

	// Start attacking the aircraft //
	mVectorOfInactiveEnemies[cocos2d::random(0, size - 1)]->StartAttacking(aircraftCurrentPosition);
}

std::vector<Enemy*> EnemyManagement::GetAVectorOfEnemies() const
{ 
	return mVectorOfEnemies;
}

std::vector<Enemy*> EnemyManagement::GetAVectorOfActiveEnemies() const
{
	std::vector<Enemy*> mVectorOfActiveEnemies;

	for (Enemy* enemy : mVectorOfEnemies)
	{
		if (enemy->IsActive())
		{
			mVectorOfActiveEnemies.push_back(enemy);
		}
	}

	return mVectorOfActiveEnemies;
}
