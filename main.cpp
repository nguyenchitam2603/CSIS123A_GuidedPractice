/*
* Name: Chi Tam Nguyen
* ID: 0588491
* Date: 07/10/2021
* Guided Practice: 7 - File IO
* Description: main.cpp
*              + Test the stream insertion and stream extraction operators. 
*              + Test operator overloads of the class Fraction.
*              + Test file writing and reading.
*/

#include <fstream>
#include <iostream>
#include <string>

#include "Fraction.h"

using namespace std;

void writeFractions(int amount);
void readFractions();
void writeNumbers(int amount);
void readNumbers();

int main()
{
	writeFractions(15);
	readFractions();

	return 0;
}

void writeFractions(int amount)
{
	ofstream outFile("Fractions.txt");
	if (!outFile)
	{
		cout << "Unable to open the file for writing" << endl;
		exit(1);
	}
	else
	{
		for (int index = 0; index < amount; ++index)
		{
			int numerator = rand();
			int denominator = rand();
			Fraction f(numerator, denominator);
			outFile << f.getFraction() << endl;
		}
		outFile.close();
	}
}

void readFractions()
{
	ifstream inFile("Fractions.txt");
	if (!inFile)
	{
		cout << "Unable to open the file for reading" << endl;
		exit(1);
	}
	else
	{
		string input;
		while (inFile >> input)
		{
			cout << input << endl;
		}
		inFile.close();
	}
}

void writeNumbers(int amount)
{
	ofstream outFile("Numbers.txt");
	if (!outFile)
	{
		cout << "Unable to open the file for writing" << endl;
		exit(1);
	}
	else
	{
		for (int i = 0; i < amount; ++i)
		{
			outFile << rand() % 100 << endl;
		}
		outFile.close();
	}
}

void readNumbers()
{
	ifstream inFile("Numbers.txt");
	if (!inFile)
	{
		cout << "Unable to open the file for reading" << endl;
		exit(1);
	}
	else
	{
		string input;
		while (inFile >> input)
		{
			cout << input << endl;
		}
		inFile.close();
	}
}
