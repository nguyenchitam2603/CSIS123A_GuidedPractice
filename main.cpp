/*
* Name: Chi Tam Nguyen
* ID: 0588491
* Date: 06/26/2021
* Guided Practice: 4 - Friends
* Description: main.cpp - Test operator overloads of the class Fraction
*/

#include <iostream>
#include "Fraction.h"

int main()
{
	Fraction f1(-5, 4);
	Fraction f2("-13 27");
	Fraction f3, f4, f5, f6, f7, f8;

	f3 = f1 + f2;
	f4 = f1 - f2;
	f5 = f1 * f2;
	f6 = f1 / f2;
	f8 = f7 = f4;

	f3.printFraction();
	f4.printFraction();
	f5.printFraction();
	f6.printFraction();
	f7.printFraction();
	f8.printFraction();

	return 0;
}