// Zad9.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

float f1(float x);
float f2(float x);
float Simpson(float a, float b, int m, float f(float x));

int main()
{
	float m = 10, p;

	system("cls");

	cout << endl << endl << "Calka pierwsza: " << Simpson(-2, 3, 10, f1);
	cout << endl << endl << "Calka druga: " << Simpson(0, 1, 10, f2);

	_getch();
	return 0;
}

float f1(float x)
{
	return 3 * x * x;
}

float f2(float x)
{
	return sin(x * x);
}

float Simpson(float a, float b, int m, float f(float x))
{
	float h = (b - a) / m;

	float parzyste = 0;
	float nieparzyste = 0;
	for (int i = 1; i < m; i++)
	{
		if (i % 2 == 0)
			parzyste += f(a + i * h);
		else
			nieparzyste += f(a + i * h);
	}

	return h * (f(a) + f(b) + 4 * nieparzyste + 2 * parzyste) / 3;
}

