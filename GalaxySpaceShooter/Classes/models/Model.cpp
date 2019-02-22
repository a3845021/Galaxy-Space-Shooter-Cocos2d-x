#include "Model.h" 
 
Model::Model()
{  
	mIsActive = false;
} 

bool Model::IsActive() const
{ 
	return mIsActive; 
}

cocos2d::Vec2 Model::GetCurrentPosition() const
{ 
	return mObjectSprite->getPosition(); 
}