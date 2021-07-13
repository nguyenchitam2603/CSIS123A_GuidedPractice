/*
* Name: Chi Tam Nguyen
* ID: 0588491
* Date: 07/10/2021
* Guided Practice: 8 - Recursion
* Description: main.cpp - Test recursion
*/

#include <fstream>
#include <iostream>
#include <string>

#include "Fraction.h"

using namespace std;

void writeFractions(int amount);
void readFractions();
int sumASCII(string arg);

int main()
{
	string input;
	cout << "Enter a string: ";
	getline(cin, input);
	int sum = sumASCII(input);
	cout << "The sum of the ASCII characters in the input string is " << sum << " " << endl;

	return 0;
}

int sumASCII(const string arg)
{
	int sum;

	if (arg.empty())
	{
		sum = 0;
	}
	else
	{
		sum = arg[0] + sumASCII(arg.substr(1));
	}

	return sum;
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
