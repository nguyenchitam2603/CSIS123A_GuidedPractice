/*
* Name: Chi Tam Nguyen
* ID: 0588491
* Date: 06/26/2021
* Guided Practice: 4 - Friends
* Description: main.cpp - Test operator overloads of the class Fraction, as well as the
*                         stream insertion and stream extraction operators
*/

#include <iostream>

#include "Fraction.h"

using namespace std;

int main()
{
	Fraction f1, f2;
	Fraction f3, f4, f5, f6, f7, f8;

	cin >> f1;
	cin >> f2;

	f3 = f1 + f2;
	f4 = f1 - f2;
	f5 = f1 * f2;
	f6 = f1 / f2;
	f8 = f7 = f4;

	cout << f3;
	cout << f4;
	cout << f5;
	cout << f6;
	cout << f7;
	cout << f8;

	return 0;
}

istream& operator >> (istream& is, Fraction& f)
{
	cout << "Enter a numerator: ";
	is >> f.num;
	cout << "Enter a denominator: ";
	is >> f.den;
	return is;
}

ostream& operator << (ostream& os, const Fraction& f)
{
	os << "The fraction is: " << f.num << "/" << f.den << endl;
	return os;
}
