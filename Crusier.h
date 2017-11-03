#pragma once
#include "Ship.h"

class Crusier : public Ship
{
public:
	Crusier();
	Crusier(string name,int xloc,int yLoc,Alignment align);
	void move();//method always moves along the vector (1, 2) 
	
	void attack(Ship *target);
protected:
	Crusier(string name, int xLoc, int yLoc, Alignment align, int MaxHealth, int range, int attackPower);
private:

};
//Pre:must have ship name, integers for location and see if it is us them or chaotic 
//Post: wll have to write it out in the unit testing
inline Crusier::Crusier() : Ship("Veeram",0, 0, us, 50, 50 , 5)
{

}
//Pre:declaring ship name, integers for location and see if it is us them or chaotic 
//Post: derived from the ship class
inline Crusier::Crusier(string name, int xLoc, int yLoc, Alignment align) : Ship(name, xLoc, yLoc, align, 50, 50, 5)
{

}
//Pre:must be alive
//Post:will move up one and right 2
inline void Crusier::move()
{
	xLoc += 1;
	yLoc += 2;
	if (getCurrentHealth() == getMaxHealth()|| getCurrentHealth() == 0)
	{
		// add nothing
	}
	else if (getCurrentHealth() < getMaxHealth())
	{
		accessDamage(-1);
	}
}
//Pre:must be alive, opponete must be alive, must be in range, cant be their teammate
//Post: then can attack
inline void Crusier::attack(Ship * target)
{
	if (getCurrentHealth() > 0 && target ->getCurrentHealth() > 0 && 
		(target->getDistance(this) <= getRange() && target->GetAlign() != GetAlign()))//making sure we are not dead and they are not dead and make sure they are on my team and not their team
	{
		target->accessDamage(GetattackPower());//full force attack
	}
	
}
//Pre:declaring ship name, integers for location and see if it is us them or chaotic 
//Post: derived from the ship class
inline Crusier::Crusier(string name, int xLoc, int yLoc, Alignment align, int MaxHealth, int range, int attackPower): Ship(name, xLoc, yLoc, align, MaxHealth, range, attackPower)
{

}
