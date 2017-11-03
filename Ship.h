#pragma once
#include <string>
#include <math.h>
#include <iostream>
using namespace std;

enum Alignment { us, them, chaotic };
class Ship
{

public:
	Ship();
	Ship(string name, int x, int y, Alignment Align, int maxHeal, int rgn, int attackPower);
	void virtual attack(Ship *target);
	int GetX(), GetY();
	Alignment GetAlign();
	string virtual Status();
	void virtual move();
	void changeAlign();
	void accessDamage(int amt);
	int getCurrentHealth();
	int getMaxHealth();
	double getDistance(Ship *target);
	int getRange();
	int GetattackPower();
	string getName();
protected://only derived classes can access this 
	int xLoc;
	int yLoc;
private:
	string getType();
	string name;
	int range;
	int currentHealth;
	int attackPower;
	int maxHealth;
	Alignment align;
};
//Pre: thigs are defined
//Post: all things are defined
inline Ship::Ship()//default constructor when someone creates a ship and does not give us anything
{
	xLoc = 0;
	yLoc = 0;
	this->name = "jake";
	this->align = them;
	this->currentHealth = 50;
	maxHealth = 50;
	this->attackPower = 5;
	range = 0;
}
//Pre: things are defined
//Post: all things are defined
inline Ship::Ship(string name, int x, int y, Alignment Align, int maxHeal, int rgn, int attackPower)
{
	xLoc = x;
	yLoc = y;
	this->name = name;
	this->align = Align;
	this->currentHealth = maxHeal;
	maxHealth = maxHeal;
	this->attackPower = attackPower;
	range = rgn;
}
//Pre: nothing 
//Post: nothing
inline void Ship::attack(Ship *target)
{
}
//Pre: must be a number
//Post: give x location
inline int Ship::GetX()
{
	return xLoc;
}
//Pre: must be a number
//Post: will give y location
inline int Ship::GetY()
{
	return yLoc;
}
//Pre: must be battle , corvette, crusier, repair
//Post: will determin us them chaotic
inline Alignment Ship::GetAlign()
{
	return align;
}
//Pre: must have string"", and type of ship and must be an integer
//Post: will set ship to thoese stats
inline string Ship::Status()
{
	string str = ""; 
	str += "name: " + getName();
	str += "type ship: " + getType();
	str += "Health:" + getCurrentHealth();
	str += "Location: (" + to_string(xLoc) + ", "  + to_string(yLoc) + ")" ;
	
	
	return string();
}
//Pre: mothing
//Post:nothing
inline void Ship::move()
{
}
//Pre: align is defined 
//Post: makes opponet them to us or us to them
inline void Ship::changeAlign()
{
	if (align = them)
	{
		align = us;
	}
	else if (align = us)
	{
		align = them;
	}
}
//post: health must be above 0 and less than 50
//pre: amount must be an integer
inline void Ship::accessDamage(int amt)
{
	currentHealth -= amt;
	if (currentHealth < 0)
	{
		currentHealth = 0;
	}
	else if (currentHealth > maxHealth)
	{
		currentHealth = maxHealth;
	}
}
//Pre :must be an integer
//post: will be the current health
inline int Ship::getCurrentHealth()
{
	return currentHealth;
}
//Pre: must be an integer
//Post: will be max health
inline int Ship::getMaxHealth()
{
	return maxHealth;
}
//Pre: must be integers
//Post: will give distance between two points
inline double Ship::getDistance(Ship* target)
{
	return (sqrt((this->GetX() - target->GetX()) * (this->GetX() - target->GetX()) + (this->GetY() - target->GetY()) * (this->GetY() - target->GetY())));
}

//Pre: must be an integers
//Post: will give range and see if ship is in range of another 
inline int Ship::getRange()
{
	return range;
}
//Pre: must be an integer
//Post:  will give attack power
inline int Ship::GetattackPower()
{
	return attackPower;
}
//Pre: must be a string""
//Post:will return name of ship
inline string Ship::getName()
{
	return name;
}
//Pre: must be one of the ships
//Post: will return type of ship
inline string Ship::getType()
{
	return string();
}
