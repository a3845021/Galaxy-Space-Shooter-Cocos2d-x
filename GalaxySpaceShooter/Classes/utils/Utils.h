#pragma once

#include "cocos2d.h"

class Utils
{
private:
	static std::string sPlanetNames[]; 
	static std::string sPlanetDescriptions[];

public:
	static int GetTheBestScore(const int& currentScore);
	static int GetTheBackgroundIndex();
	static void ChangeTheBackgroundIndex();
	static cocos2d::Vector<cocos2d::SpriteFrame*> GetAVectorOfSpriteFramesByCache(const char* format, const int& count);
	static cocos2d::Vector<cocos2d::SpriteFrame*> GetAVectorOfSpriteFramesByProcedure(cocos2d::Sprite* sampleSprite, const char* format, const int& count);
	static char* GetInitialOfTheExplosionEffect(const int& mDamageAmount);
	static int GetTheNumberOfPicturesOfTheExplosionEffect(const int& mDamageAmount);
	static std::string GetPlanetNameBasedOnTheIndex(const int& index);
	static std::string GetPlanetDescriptionBasedOnTheIndex(const int& index); 
};