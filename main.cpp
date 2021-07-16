/*
* Name: Chi Tam Nguyen
* ID: 0588491
* Date: 07/17/2021
* Guided Practice: 9 - Polymorphism
* Description: main.cpp - Test inheritance and polymorphism
*/

#include <iostream>

using namespace std;

// Animal
class Animal
{
private:
	int legs;

public:
	Animal();
	void setLegs(int legs);
	int getLegs();
	void talk();
	virtual void speak() = 0;
};

Animal::Animal()
	: legs(4)
{
}

void Animal::setLegs(int legs)
{
	this->legs = legs;
}

int Animal::getLegs()
{
	return this->legs;
}

void Animal::talk()
{
	this->speak();
}

// Cat
class Cat : public Animal
{
public:
	void speak();
};

void Cat::speak()
{
	cout << "meow" << endl;
}

// Cow
class Cow : public Animal
{
public:
	void speak();
};

void Cow::speak()
{
	cout << "moo" << endl;
}

// Dog
class Dog : public Animal
{
public:
	void speak();
};

void Dog::speak()
{
	cout << "woof" << endl;
}

int main()
{
	Cat cat;
	Dog dog;
	Cow cow;
	Animal* animal[3];
	animal[0] = &cat;
	animal[1] = &dog;
	animal[2] = &cow;

	for (int index = 0; index < 3; ++index)
	{
		animal[index]->talk();
	}

	return 0;
}
