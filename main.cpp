/*
* Name: Chi Tam Nguyen
* ID: 0588491
* Date: 06/26/2021
* Guided Practice: 6 - Static Members
* Description: main.cpp - Test the stream insertion and stream extraction operators, 
*                         operator overloads of the class Fraction, and track the count static variable
*/

#include <iostream>

#include "Fraction.h"

using namespace std;

int main()
{
	Fraction* f1 = new Fraction();
	cin >> *f1;
	Fraction::printCount();

	Fraction* f2 = new Fraction(-3, 4);
	Fraction::printCount();

	Fraction* f3 = new Fraction((*f1) + (*f2));
	Fraction* f4 = new Fraction((*f1) - (*f2));
	Fraction* f5 = new Fraction((*f1) * (*f2));
	Fraction* f6 = new Fraction((*f1) / (*f2));
	Fraction* f7 = new Fraction(*f4);

	cout << *f3;
	cout << *f4;
	cout << *f5;
	cout << *f6;
	cout << *f7;
	Fraction::printCount();
	
	delete f1;
	delete f2;
	delete f3;
	delete f4;
	delete f5;
	delete f6;
	delete f7;
	Fraction::printCount();

	return 0;
}
