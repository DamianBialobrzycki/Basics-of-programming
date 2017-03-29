// Zad1.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	float a = 0, b = 0, c = 0, d = 0, e = 0,f = 0, x = 0, y = 0;
	bool good = false;

	do
	{
		cout << "Podaj wspolczynnik a: ";
		cin >> a;
		cout << "Podaj wspolczynnik b: ";
		cin >> b;
		cout << "Podaj wspolczynnik c: ";
		cin >> c;
		cout << "Podaj wspolczynnik d: ";
		cin >> d;
		cout << "Podaj wspolczynnik e: ";
		cin >> e;
		cout << "Podaj wspolczynnik f: ";
		cin >> f;

		// Jesli mianownik wynosi 0
		if ((a*d - b*c) == 0 || (a*d - b*c) == 0)
		{
			cout << endl <<  "Nie mozna dzielic przez 0! Podaj nowe wspolczynniki:" << endl;
		}
		else
		{
			x = (e*d - b*f) / (a*d - b*c);
			y = (a*f - e*c) / (a*d - b*c);
			//Obliczenie i wyjscie z petli
			good = true;

		}
	} while (good == false);
	

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);

	cout << endl;
	
	cout << "x = "; 
	cout.width(9); 
	cout << x << endl;
	
	cout << "y = ";
	cout.width(9); 
	cout<< y << endl;
	_getch();

	return 0;
}

