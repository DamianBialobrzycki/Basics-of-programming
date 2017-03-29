// Zad3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	int n = 0;
	
	do
	{
		cout << "Podaj liczbe (rozna od zera): ";
		cin >> n;
	} while (n == 0);
	

	cout << endl << "PETLA FOR" << endl;
	cout << "Dzielniki liczby: " << endl;

	if (n < 0)
		n = -n;

	//Sposob 1. Petla FOR
	for (int i = -n; i <= n; i++)
	{
		if (i == 0)
			continue;
		if (n%i == 0)
			cout << i << " ";
	}
	
	cout << endl << endl;

	//Sposob 2. Petla WHILE
	cout << "PETLA WHILE" << endl;
	cout << "Dzielniki liczby: " << endl;

	int j = -n;
	while (j != (n + 1))
	{
		if (j != 0)
			if (n%j == 0)
				cout << j << " ";
		j++;
	}

	cout << endl << endl;

	//Sposob 2. Petla DO...WHILE
	cout << "PETLA DO...WHILE" << endl;
	cout << "Dzielniki liczby: " << endl;

	int k = -n;
	do
	{
		if (k != 0)
			if (n%k == 0)
				cout << k << " ";
		k++;
	} while (k != (n+1));
	cout << endl;
	_getch();
	return 0;
}

