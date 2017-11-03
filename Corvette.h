#pragma once
#include "Ship.h"

class Corvette : public Ship
{
public:
	void move();// always moves along the vector (5, 5) 
	void attack(Ship * target);
	// Everyone loves corvettes so their attack 
	// flips ships in range to its state 
	// (if self is us, turns them to us,
	// if self is them, turns us to them)
	Corvette();
	Corvette(string name, int xLoc, int yLoc, Alignment align);
private:

};
//Pre:must be alive 
//Post:will move up 5 and right 5
void Corvette::move()
{
	xLoc += 5;
	yLoc += 5;
	if (getCurrentHealth() == getMaxHealth() || getCurrentHealth() == 0)
	{
		// does not return anything
	}
	else if (getCurrentHealth() < getMaxHealth())
	{
		accessDamage(-1);
	}
}
//Pre:must be alive, opponete must be alive, must be in range, cant be their teammate
//Post: then can attack
void Corvette::attack(Ship * target)
{
	if (getCurrentHealth() > 0 && target->getCurrentHealth() > 0 &&
		(target->getDistance(this) <= getRange() && target->GetAlign() != GetAlign()))//making sure we are not dead and they are not dead and make sure they are on my team and not their team
	{
		target->changeAlign();//going to to the dark side
	}

}
//Pre:string, int, int, alignment, 
//Post: nothing
inline Corvette::Corvette() : Ship("battleship", 0, 0, us, 20, 25, 0)
{
}
//Pre:name string, see where it it located, see whos team its on
//Post: plug in on the unit testing
inline Corvette::Corvette(string name, int xLoc, int yLoc, Alignment align)
{
}
