#include "Utils.h"
#include "common/CommonValues.h"

#include "cocos2d.h"

std::string Utils::sPlanetNames[] = { "Uranus", "Neptune", "Saturn", "Pluto", "Mars", "Lava","Jupiter","Venus","Mercury","Earth" };
std::string Utils::sPlanetDescriptions[] = { "The personification of heaven in ancient myth", "Roman God of water",
"Roman God of agriculture", "Roman God of the underworld, Hades", "Roman God of war", "Mysterious solar system world of Gods",
"Ruler of the Roman Gods","Roman Goddess of love and beauty","Messenger of the Roman Gods","The land of humans and Gods" };

int Utils::GetTheBestScore(const int& currentScore)
{
	cocos2d::UserDefault* userDefault = cocos2d::UserDefault::getInstance();

	auto bestscore = userDefault->getIntegerForKey("HIGHSCORE", 0);

	if (currentScore > bestscore)
	{
		bestscore = currentScore;

		userDefault->setIntegerForKey("HIGHSCORE", bestscore);
	}

	userDefault->flush();

	return bestscore;
}

int Utils::GetTheBackgroundIndex()
{
	cocos2d::UserDefault* userDefault = cocos2d::UserDefault::getInstance();
	 
	return userDefault->getIntegerForKey("BACKGROUND_INDEX", 0);
}

void Utils::ChangeTheBackgroundIndex()
{
	cocos2d::UserDefault* userDefault = cocos2d::UserDefault::getInstance();

	auto currentBackgroundIndex = userDefault->getIntegerForKey("BACKGROUND_INDEX", 0);

	if (currentBackgroundIndex == 0)
		userDefault->setIntegerForKey("BACKGROUND_INDEX", 1);
	else
		userDefault->setIntegerForKey("BACKGROUND_INDEX", 0);
}

cocos2d::Vector<cocos2d::SpriteFrame*> Utils::GetAVectorOfSpriteFramesByCache(const char* format, const int& count)
{
	auto spritecache = cocos2d::SpriteFrameCache::getInstance();

	cocos2d::Vector<cocos2d::SpriteFrame*> animFrames;

	char str[100];

	for (int i = 1; i <= count; i++)
	{
		sprintf(str, format, i);
		animFrames.pushBack(spritecache->getSpriteFrameByName(str));
	}

	return animFrames;
}

cocos2d::Vector<cocos2d::SpriteFrame*> Utils::GetAVectorOfSpriteFramesByProcedure(cocos2d::Sprite* sampleSprite, const char* format, const int& count)
{
	cocos2d::Vector<cocos2d::SpriteFrame*> animFrames;

	char str[100];

	for (int i = 1; i <= count; i++)
	{
		sprintf(str, format, i);
		animFrames.pushBack(cocos2d::SpriteFrame::create(str, cocos2d::Rect(0, 0, sampleSprite->getContentSize().width, sampleSprite->getContentSize().height)));
	}

	return animFrames;
}

char* Utils::GetInitialOfTheExplosionEffect(const int& mDamageAmount)
{
	switch (mDamageAmount)
	{
	case ENEMY_DAMAGE_AMOUNT_LEVEL_0:
		return "3p%d.png";
	case ENEMY_DAMAGE_AMOUNT_LEVEL_1:
		return "1p%d.png";
	case ENEMY_DAMAGE_AMOUNT_LEVEL_2:
		return "2p%d.png";
	case ENEMY_DAMAGE_AMOUNT_LEVEL_3:
		return "3p%d.png";
	default:
		return "3p%d.png";
	}
}

int Utils::GetTheNumberOfPicturesOfTheExplosionEffect(const int& mDamageAmount)
{
	switch (mDamageAmount)
	{
	case ENEMY_DAMAGE_AMOUNT_LEVEL_0:
		return 29;
	case ENEMY_DAMAGE_AMOUNT_LEVEL_1:
		return 35;
	case ENEMY_DAMAGE_AMOUNT_LEVEL_2:
		return 27;
	case ENEMY_DAMAGE_AMOUNT_LEVEL_3:
		return 29;
	default:
		return 29;
	}
}

std::string Utils::GetPlanetNameBasedOnTheIndex(const int& index)
{
	return sPlanetNames[index];
}

std::string Utils::GetPlanetDescriptionBasedOnTheIndex(const int& index)
{
	return sPlanetDescriptions[index];
}