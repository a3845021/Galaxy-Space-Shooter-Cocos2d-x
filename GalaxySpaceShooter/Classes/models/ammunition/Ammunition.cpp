#include "Ammunition.h"   
#include "common/CommonValues.h" 
 
Ammunition::Ammunition(const int& damageAmount) : Model()
{     
	mDamageAmount = damageAmount;
} 

int Ammunition::GetDamageAmount() const
{
	return mDamageAmount;
}