#pragma once
#include "Ship.h"

class Battle : public Ship
{
public:
	//methods
	void attack(Ship *target);//attacks and fires torpedo >0 and // does additional 10 damage, 1 less torpedo 
		// always moves along the vector (-1, -1) 
		
	string status(); // also indicates number of torpedoes
	void move();
	Battle();
	Battle(string name, int xLoc, int yLoc, Alignment align);
private:
	//attributes // range is 10, maxHealth =100 ,attack = 10 
		int	torpedoes;//int initially 10
};
//Pre:must be alive, opponete must be alive, must be in range, cant be their teammate
//Post: then can attack
void Battle::attack(Ship * target)
{
	if (getCurrentHealth() > 0 && target->getCurrentHealth() > 0 &&
		(target->getDistance(this) <= getRange() && target->GetAlign() != GetAlign()))//making sure we are not dead and they are not dead and make sure they are on my team and not their team
	{
		if (torpedoes > 0)
		{
			target->accessDamage(GetattackPower() + 10);
			torpedoes -= 1;
		}
		else
		{
			target->accessDamage(GetattackPower());//full force attack
		}
	}
}
//Pre:msut be alive and opponet must be alive and in range
//Post: will shoot torpedo and have >10
string Battle::status()//print out number of torpedos 
{
	string str1 = Ship::Status() + "\ntorpedos: " + to_string(torpedoes)  ;
	return str1;
}
//Pre:must be alive 
//Post:will move left 1 and down 1
inline void Battle::move()
{
	xLoc -= 1;
	yLoc -= 1;
	if (getCurrentHealth() == getMaxHealth() || getCurrentHealth() == 0)
	{
		// does not return anything
	}
	else if (getCurrentHealth() < getMaxHealth())
	{
		accessDamage(-1);
	}
}
//Pre:must have ship name, integers for location and see if it is us them or chaotic 
//Post: wll have to write it out in the unit testing
inline Battle::Battle() : Ship("Battlemale", 0, 0, us, 100, 10, 10)
{
	torpedoes = 10;
}
//Pre:declaring ship name, integers for location and see if it is us them or chaotic 
//Post: derived from the ship class
inline Battle::Battle(string name, int xLoc, int yLoc, Alignment align) : Ship(name, xLoc, yLoc, align, 100, 10, 10) 
{
	torpedoes = 10;
}
