#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TrekWarz/Battle.h"
#include"../TrekWarz/Corvette.h"
#include "../TrekWarz/Crusier.h"
#include "../TrekWarz/Repair.h"
#include "../TrekWarz/Ship.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)//cursier 1
		{
			Crusier x("veeram", 2, 2, us);
			x.move();

			Assert::AreEqual(x.GetX(), 3);
			Assert::AreEqual(x.GetY(), 4);
		}
		TEST_METHOD(TestMethod2)//battle 1
		{
			Battle x("battlemale", 1, 1, us);
			x.move();

			Assert::AreEqual(x.GetX(), 0);
			Assert::AreEqual(x.GetX(), 0);
		}
		TEST_METHOD(TestMethod3)//crusier 2
		{
			Crusier x("veeram", 2, 2, us);

			Battle y("battlemale", 2, 3, them);
			x.attack(&y);
			Assert::AreEqual(y.getCurrentHealth(), 95);
		}
		TEST_METHOD(TestMethod4)//crusier 3
		{
			Crusier x("veeram", 3, 3, us);
			Battle y("BlackPanther", 3, 90, them);
			x.attack(&y);
			Assert::AreEqual(y.getCurrentHealth(), 100);
		}
		TEST_METHOD(TestMethod5)//corvette 1
		{
			Corvette x("veeram", 3, 3, us);
			Battle y("suhDude", 4, 4, chaotic);
			x.attack(&y);
			Assert::AreEqual(y.getCurrentHealth(), 100);
		}
		TEST_METHOD(TestMethod6)//corvette 2
		{
			Corvette x("veeram", 3, 3, chaotic);
			Battle y("suhDude", 4, 4, chaotic);
			x.attack(&y);
			Assert::AreEqual(y.getCurrentHealth(), 100);
		}
		TEST_METHOD(TestMethod7)//corvette 3
		{
			Corvette x("veeram", 2, 2, us);
			Repair y("yomama", 3, 3, them);
			x.attack(&y);
			Assert::AreEqual(y.getCurrentHealth(), 20);
		}
		TEST_METHOD(TestMethod8)//Battle 2
		{
			Battle x("theBlackPanther", 5, 5, us);
			Repair y("iwilldie", 70, 20, them);
			x.attack(&y);
			Assert::AreEqual(y.getCurrentHealth(), 20);
		}
		TEST_METHOD(TestMethod9)//Battle 3
		{
			Battle x("BlackPanther", 6, 6, chaotic);
			Battle y("ironman", 4, 4, us);
			x.attack(&y);
			Assert::AreEqual(y.getCurrentHealth(), 80);
		}
		TEST_METHOD(TestMethod10)//repair 1
		{
			Repair x("spongeBob", 0, 0, us);
			Battle y("ironman", 4, 4, us);
			Assert::AreEqual(y.getCurrentHealth(), 100);
		}
		TEST_METHOD(TestMethod11)//repair 2
		{
			Repair x("bobspone", 0, 0, them);
			Repair y("pinhead", 1, 1, us);
			Assert::AreEqual(y.getCurrentHealth(), 20);
		}
		TEST_METHOD(TestMedod12)//repair 3
		{
			Repair x("bobspone", 0, 0, them);
			Crusier z("ILoveCIS", 100, 100, us);
			Assert::AreEqual(z.getCurrentHealth(), 50);
		}
	};
	
}