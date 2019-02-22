#include "Shooter.h"
#include "common/CommonValues.h"

Shooter::Shooter(const int& healthMultiplier)
{
	// Set the very first health value //
	mCurrentHealth = MAX_HEALTH * healthMultiplier;

	// Set the initial life state //
	mIsDead = false;
}

bool Shooter::IsDead() const
{
	return mIsDead;  
}

// TODO: optimize performance here // 

std::vector<Ammunition*> Shooter::GetAVectorOfActiveAmmunitions() const
{ 
	std::vector<Ammunition*> mVectorOfActiveAmunitions;
	 
	for (int i = 1; i <= mMapOfVectorsOfAmmunitions.size(); i++)
	{ 
		for (Ammunition* ammunition : mMapOfVectorsOfAmmunitions.at(i))
		{
			if (ammunition->IsActive())
			{
				mVectorOfActiveAmunitions.push_back(ammunition);
			}
		}
	} 

	return mVectorOfActiveAmunitions;
}