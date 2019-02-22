#pragma once
   
class IDamagable
{ 
public:
	virtual void Damage(int takenHealth) = 0;
};