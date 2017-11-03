#include "stdafx.h"
#include <iostream>
#include <ostream>
#include "Poly.h"
using namespace std;

//Pre:make PolynomialPtr new termnode()
//post:will create new termnode()
PolyType::PolyType()
{
	PolynomialPtr = new TermNode();
}
//Pre:will declare coeficient and exponent varibles
//post:will make coeficient and exponent varibles
PolyType::PolyType(int coeficient, int exponent)
{
	PolynomialPtr = new TermNode();
	PolynomialPtr->coef = coeficient;
	PolynomialPtr->exp = exponent;
}
//Pre:will make new pointer for poly, and return value for poly
//post:as long as thecurrentptr is nullptr, then it should set current node to next poly. 
PolyType::PolyType(const PolyType & polynomial)
{
	TermNode *TheCurrentPtr = polynomial.PolynomialPtr;//declaring
	TermNode *NewCurrentPtr = this->PolynomialPtr;
	TheCurrentPtr = NewCurrentPtr->next;
	NewCurrentPtr = NewCurrentPtr->next->next;

	while (TheCurrentPtr != nullptr)
	{
		PolynomialPtr = new TermNode;
		TheCurrentPtr = PolynomialPtr;
		TheCurrentPtr = new TermNode;
		TheCurrentPtr->coef = TheCurrentPtr->coef;
		TheCurrentPtr->exp = TheCurrentPtr->exp;
		TheCurrentPtr = TheCurrentPtr->next;
		NewCurrentPtr = NewCurrentPtr->next;
	}
	//return *this;
}
//Pre:will go throuhg evey pointer until it hits nullptr
//post:when it hit nullptr, it will then delete everything before nullptr
PolyType::~PolyType()//destructor
{
	TermNode *current = new TermNode;
	while (current != nullptr)
	{
		TermNode *next = current->next;
		delete current;
		current = next;
	}
}
//pre:this will help print out for multpilcation, addition, diff, and inter
//Post:will print out the functions properly
PolyType PolyType::operator=(const PolyType & polynomial)
{
	TermNode *TheCurrentPtr = polynomial.PolynomialPtr;//declaring
	TermNode *NewCurrentPtr = this->PolynomialPtr;

	while (TheCurrentPtr != nullptr)
	{
		TheCurrentPtr = new TermNode;
		NewCurrentPtr = new TermNode;
		TheCurrentPtr->coef = TheCurrentPtr->coef;//shallow copy is bad
		TheCurrentPtr->exp = TheCurrentPtr->exp;//shallow copy is bad
		TheCurrentPtr = TheCurrentPtr->next->next;
		NewCurrentPtr = NewCurrentPtr->next;
	}
	return *this;
}
//pre:adds two poly, with eachother
//post: will return poly1+poly2
PolyType PolyType::operator +(const PolyType & polynomial) const
{
	PolyType tempPolyType;
	//while (tempPolyType != nullptr)
	{
		if (this->PolynomialPtr->exp >= polynomial.PolynomialPtr->exp)
		{
			tempPolyType.PolynomialPtr = this->PolynomialPtr;
			tempPolyType.PolynomialPtr->next = polynomial.PolynomialPtr;
			PolynomialPtr->next = PolynomialPtr->next->next;
		}
		else
		{
			tempPolyType.PolynomialPtr = polynomial.PolynomialPtr;
			tempPolyType.PolynomialPtr->next = this->PolynomialPtr;
			PolynomialPtr->next = PolynomialPtr->next->next;
		}
		return tempPolyType;
	}
}
//pre: multiplys 2 polys with eachother
//post:will return poly1*poly2
PolyType PolyType::operator *(const PolyType & polynomial) const
{
	PolyType tempPolyType;
	tempPolyType.PolynomialPtr = new TermNode();
	TermNode *firstPtr = this->PolynomialPtr;
	TermNode *SecondPtr = polynomial.PolynomialPtr;
	TermNode *TempPolyPtr = tempPolyType.PolynomialPtr;
	TermNode *TempPolyPtrTwo, *TempPolyPtrThree;
	while (firstPtr != nullptr)
	{
		while (SecondPtr != nullptr)

		{
			TempPolyPtr->coef = firstPtr->coef * SecondPtr->coef;
			TempPolyPtr->exp = firstPtr->exp * SecondPtr->exp;

			TempPolyPtr = TempPolyPtr->next;
			TempPolyPtr = new TermNode();
			SecondPtr - SecondPtr->next;
		}
		//SecondPtr = firstPtr->next-> next;
	}

	// add like terms
	TempPolyPtr = tempPolyType.PolynomialPtr;
	TempPolyPtrTwo = tempPolyType.PolynomialPtr->next;
	TempPolyPtrThree = tempPolyType.PolynomialPtr->next;
	int PtrBaseCase = 0;
	while (TempPolyPtrTwo != nullptr)
	{
		while (TempPolyPtrThree != nullptr)
		{
			if (TempPolyPtrTwo->exp == TempPolyPtrThree->exp)
				TempPolyPtr->coef = TempPolyPtrTwo->coef + TempPolyPtrThree->coef;
			TermNode *nextPointer = new TermNode();

			for (int number = 0; number < PtrBaseCase; number++);
			{
				TempPolyPtr = TempPolyPtr->next;
				nextPointer = TempPolyPtr->next->next;
			}
			TempPolyPtr->next = nextPointer;
		}
		TempPolyPtrThree = TempPolyPtrThree->next;
		PtrBaseCase++;
	}
	TempPolyPtrTwo = TempPolyPtrTwo->next;
	return tempPolyType;
}
//pre:will take the differentation of a polynomial
//post:will retrun a poly with a higher coef, and lower exp
PolyType PolyType::differentation()
{
	PolyType tempPolyType;
	TermNode *CurrentPtr = this->PolynomialPtr;
	TermNode * tempPolyPtr = tempPolyType.PolynomialPtr;

	while (CurrentPtr != nullptr)
	{
		tempPolyPtr = new TermNode();
		tempPolyPtr->exp = CurrentPtr->exp - 1;
		tempPolyPtr->coef = CurrentPtr->coef *CurrentPtr->exp;
		CurrentPtr = CurrentPtr->next->next;
		tempPolyPtr = tempPolyPtr->next;
	}
	return tempPolyType;
}
//pre:will take the integral of a polynomial
//post:will return a poly with a lower coef, and higer exp with a const
PolyType PolyType::integration()
{
	PolyType tempPolyType;
	TermNode *CurrentPtr = this->PolynomialPtr;
	TermNode *tempPolyPtr = tempPolyType.PolynomialPtr;
	while (CurrentPtr != nullptr)
	{
		tempPolyPtr = new TermNode();
		tempPolyPtr->exp = CurrentPtr->exp + 1;
		tempPolyPtr->coef = CurrentPtr->coef / (CurrentPtr->exp + 1);
		CurrentPtr = CurrentPtr->next->next;
		tempPolyPtr = tempPolyPtr->next;
	}
	return tempPolyType;
}

//pre:needs to have an input of number ex. poly(1, 1)
//post:will output the poly as 1x^1, accordingly 
ostream & operator<<(ostream & out, const PolyType & rhs)
{
	TermNode *currentPtr = rhs.PolynomialPtr;

	cout << currentPtr->coef << "x^" << currentPtr->exp << endl;
	currentPtr = currentPtr->next;

	while (currentPtr != nullptr)
	{
		cout << "^" << currentPtr->coef << "x^" << currentPtr->exp << endl;
		currentPtr = currentPtr->next;
	}

	return out;
	// TODO: insert return statement here
}

