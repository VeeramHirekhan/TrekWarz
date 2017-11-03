#pragma once
#include "Crusier.h"

class Repair : public Crusier
{
public:
	Repair();
	Repair(string name, int xLoc, int yLoc, Alignment align);
	void attack(Ship *target);
	void move();
private:
};
//Pre:must have ship name, integers for location and see if it is us them or chaotic 
//Post: wll have to write it out in the unit testing
inline Repair::Repair() : Crusier("Repairan", 1, 1, us)
{

}
//Pre:declaring ship name, integers for location and see if it is us them or chaotic 
//Post: derived from the crusier class
inline Repair::Repair(string name, int xLoc, int yLoc, Alignment align) : Crusier(name, xLoc, yLoc, align, 20, 25, 0)
{
}
//Pre:must be within distance, and must be alive and cant be on your own team
//Post: will then attack
void Repair::attack(Ship * target)
{
	if (getCurrentHealth() > 0 && target->getCurrentHealth() > 0 &&
		(target->getDistance(this) <= getRange() && target->GetAlign() != GetAlign()))//making sure we are not dead and they are not dead and make sure they are on my team and not their team
	{
		target->accessDamage(-target->getMaxHealth());//full force attack
	}
}
//Pre:can olny if he is alive and not dead
//Post:can only move up 2 and right 1
inline void Repair::move()
{
	xLoc += 1;
	yLoc += 2;
	if (getCurrentHealth() == getMaxHealth() || getCurrentHealth() == 0)
	{
		// add nothing
	}
	else if (getCurrentHealth() < getMaxHealth())
	{
		accessDamage(-1);
	}
}
