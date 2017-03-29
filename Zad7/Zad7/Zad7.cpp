// Zad7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <cmath>

using namespace std;

float f(float x)
{
	return exp(-1.5 * x) - 0.3 * x*x;
}

float bisekcja(float a, float b, float epsilon, float f(float x))
{
	float c, a1;
	int k = 0;
	do
	{
		k++;
		a1 = a;
		c = (a + b) / 2;
		if (f(c) == 0)
			break;

		if (f(a1) * f(c) < 0)
			b = c;
		else
			a = c;

	} while (fabs(a1 - c) > epsilon);
	cout << endl << "Liczba iteracji: " << k;

	return c;
}

int main()
{
	int a = 0, b = 1;

	float epsilon, p;
	
	
	do
	{
		cout << endl << "Podaj dokladnosc obliczen: ";
		cin >> epsilon;
	} while (epsilon < 0);

	p = bisekcja(0, 1, epsilon, f);
	cout << endl << endl << "Obliczony pierwiastek: " << p;

	_getch();
	return 0;
}

