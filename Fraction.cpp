/*
* Name: Chi Tam Nguyen
* ID: 0588491
* Date: 07/10/2021
* Guided Practice: 8 - Recursion
* Description: Fraction.cpp - Definition of class Fraction. It provides functions and operator overloads
*              relating to addition, subtraction, multiplication, division, and equal.
*/

#include <iostream>
#include <sstream>

#include "Fraction.h"

using namespace std;

int Fraction::count = 0;

Fraction::Fraction()
	: Fraction(1, 1)
{
}

Fraction::Fraction(int num, int den)
{
	this->create();
	this->setFraction(num, den);
	Fraction::count++;
}

Fraction::Fraction(string arg)
{
	size_t spacePos = arg.find(" ");
	int num = stoi(arg.substr(0, spacePos));
	int den = stoi(arg.substr(spacePos + 1));
	this->create();
	this->setFraction(num, den);
	Fraction::count++;
}

Fraction::Fraction(const Fraction& f)
{
	this->create();
	this->setFraction(f.getNum(), f.getDen());
	Fraction::count++;
}

Fraction::~Fraction()
{
	delete this->num;
	delete this->den;
	Fraction::count--;
}

void Fraction::create()
{
	this->num = new int;
	this->den = new int;
}

void Fraction::setFraction(int n, int d)
{
	*this->num = n;
	*this->den = d;
}

Fraction Fraction::add(const Fraction& f)
{
	Fraction tmp;
	*tmp.num = ((*this->num) * (*f.den)) + ((*f.num) * (*this->den));
	*tmp.den = (*this->den) * (*f.den);
	return tmp;
}

Fraction Fraction::sub(const Fraction& f)
{
	Fraction tmp;
	*tmp.num = ((*this->num) * (*f.den)) - ((*f.num) * (*this->den));
	*tmp.den = (*this->den) * (*f.den);
	return tmp;
}

Fraction Fraction::mul(const Fraction& f)
{
	Fraction tmp;
	*tmp.num = (*this->num) * (*f.num);
	*tmp.den = (*this->den) * (*f.den);
	return tmp;
}

Fraction Fraction::div(const Fraction& f)
{
	Fraction tmp;
	*tmp.num = (*this->num) * (*f.den);
	*tmp.den = (*this->den) * (*f.num);

	if (*tmp.den < 0)
	{
		*tmp.num *= -1;
		*tmp.den *= -1;
	}

	return tmp;
}

int Fraction::getNum() const
{
	return *this->num;
}

int Fraction::getDen() const
{
	return *this->den;
}

void Fraction::printFraction()
{
	cout << *this->num << "/" << *this->den << endl;
}

string Fraction::getFraction() const
{
	stringstream ss;
	ss << *this->num << "/" << *this->den;
	return ss.str();
}

void Fraction::printCount()
{
	cout << "There are " << Fraction::count << " Instances" << endl;
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

bool Fraction::operator == (const Fraction& f)
{
	return (*this->num == *f.num && *this->den == *f.den);
}

istream& operator >> (istream& is, Fraction& f)
{
	cout << "Enter a numerator: ";
	is >> *f.num;
	cout << "Enter a denominator: ";
	is >> *f.den;
	return is;
}

ostream& operator << (ostream& os, const Fraction& f)
{
	os << "The fraction is: " << *f.num << "/" << *f.den << endl;
	return os;
}

int Fraction::gcd(int num, int remainder)
{
	if (remainder == 0)
		return num;
	else
		return gcd(remainder, num % remainder);
}

void Fraction::reduce()
{
	int rdc = 0;

	if (*this->den > *this->num)
		rdc = this->gcd(*this->den, *this->num);
	else if (*this->den < *this->num)
		rdc = this->gcd(*this->num, *this->den);
	else
		rdc = this->gcd(*this->num, *this->den);

	*this->den /= rdc;
	*this->num /= rdc;
}