// Zad2.cpp : Defines the entry point for the console application.
//



#include "stdafx.h"
#include <iostream>
#include <conio.h>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int main()
{
	int alfaAngle = 0;
	float r = 0, f = 0, radians = 0;

	do
	{
		cout << "Podaj kat Alfa (mniejszy od 360): ";
		cin >> alfaAngle;

		cout << "Podaj promien kola:";
		cin >> r;

	} while (alfaAngle > 360 || r <= 0);
	
	

	radians = M_PI*alfaAngle / 180;

	f = (pow(r, 2) / 2) * (radians - sin(radians));

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);
	cout << "Pole odcinka kola wynosi: " << f << endl;

	_getch();

	return 0;
}

