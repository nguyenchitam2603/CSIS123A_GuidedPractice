/*
* Name: Chi Tam Nguyen
* ID: 0588491
* Date: 06/26/2021
* Guided Practice: 4 - Friends
* Description: Fraction.cpp - Definition of class Fraction. It provides functions and operator overloads
*              relating to addition, subtraction, multiplication, division, and equal.
*/

#include <iostream>
#include "Fraction.h"

using namespace std;

Fraction::Fraction()
	: Fraction(1, 1)
{
}

Fraction::Fraction(int num, int den)
{
	this->setFraction(num, den);
}

Fraction::Fraction(string arg)
{
	size_t spacePos = arg.find(" ");
	int num = stoi(arg.substr(0, spacePos));
	int den = stoi(arg.substr(spacePos + 1));
	this->setFraction(num, den);
}

void Fraction::setFraction(int n, int d)
{
	this->num = n;
	this->den = d;
}

Fraction Fraction::add(const Fraction& f)
{
	Fraction tmp;
	tmp.num = (this->num * f.den) + (f.num * this->den);
	tmp.den = this->den * f.den;
	return tmp;
}

Fraction Fraction::sub(const Fraction& f)
{
	Fraction tmp;
	tmp.num = (this->num * f.den) - (f.num * this->den);
	tmp.den = this->den * f.den;
	return tmp;
}

Fraction Fraction::mul(const Fraction& f)
{
	Fraction tmp;
	tmp.num = this->num * f.num;
	tmp.den = this->den * f.den;
	return tmp;
}

Fraction Fraction::div(const Fraction& f)
{
	Fraction tmp;
	tmp.num = this->num * f.den;
	tmp.den = this->den * f.num;

	if (tmp.den < 0)
	{
		tmp.num *= -1;
		tmp.den *= -1;
	}

	return tmp;
}

void Fraction::printFraction()
{
	cout << this->num << "/" << this->den << endl;
}

int Fraction::getNum() const
{
	return this->num;
}

int Fraction::getDen() const
{
	return this->den;
}

Fraction Fraction::operator + (const Fraction& f)
{
	return this->add(f);
}

Fraction Fraction::operator - (const Fraction& f)
{
	return this->sub(f);
}

Fraction Fraction::operator * (const Fraction& f)
{
	return this->mul(f);
}

Fraction Fraction::operator / (const Fraction& f)
{
	return this->div(f);
}

Fraction& Fraction::operator = (const Fraction& f)
{
	this->setFraction(f.getNum(), f.getDen());
	return *this;
}