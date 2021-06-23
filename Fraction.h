/*
* Name: Chi Tam Nguyen
* ID: 0588491
* Date: 06/26/2021
* Guided Practice: 5 - Dynamic Memory
* Description: Fraction.h - Declaration of class Fraction. It provides functions and operator overloads
*              relating to addition, subtraction, multiplication, division, and equal.
*/

#pragma once

#include <istream>
#include <ostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;

class Fraction
{
private:
	int* num;
	int* den;

public:
	// Constructors
	Fraction();
	Fraction(int num, int den);
	Fraction(string arg);
	// Copy Constructor
	Fraction(const Fraction& f);
	// Destructor
	~Fraction();

	void create();
	void setFraction(int n, int d);
	Fraction add(const Fraction& f);
	Fraction sub(const Fraction& f);
	Fraction mul(const Fraction& f);
	Fraction div(const Fraction& f);
	int getNum() const;
	int getDen() const;
	void printFraction();
	string toString();

	// Operators Overload
	Fraction operator + (const Fraction& f);
	Fraction operator - (const Fraction& f);
	Fraction operator * (const Fraction& f);
	Fraction operator / (const Fraction& f);
	Fraction& operator = (const Fraction& f);
	bool operator == (const Fraction& f);

	friend istream& operator >> (istream& is, Fraction& f);
	friend ostream& operator << (ostream& os, const Fraction& f);
};
