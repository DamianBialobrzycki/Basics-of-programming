// Zad8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int menu();
float f1(float x);
float f2(float x);
float f3(float x);
float bisekcja(float a, float b, float epsilon, float f(float x));

int main()
{
	float epsilon, p;
	int wybor;
	bool end = false;

	do
	{
		wybor = menu();
		if (wybor != 4)
			do
			{
				cout << endl << "Podaj dokladnosc obliczen: ";
				cin >> epsilon;
			} while (epsilon < 0);

			switch (wybor)
			{
			case 1:
				p = bisekcja(0, 1, epsilon, f1);
				break;
			case 2:
				p = bisekcja(1.5, 2.2, epsilon, f2);
				break;
			case 3:
				p = bisekcja(-2, 0, epsilon, f3);
				break;
			case 4:
				end = true;
				break;
			}

			if (wybor != 4)
			{
				cout << endl << endl << "Pierwiastek: " << p;
				_getch();
			}

	} while (!end);

	return 0;
}

float f1(float x)
{
	return exp(-1.5 * x) - 0.3 * x * x;
}

float f2(float x)
{
	return (M_PI - x * x + sin(x)) / sqrt(25 - x);
}

float f3(float x)
{
	return sin(x) * cos(x) + 5 * x + 1;
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

int menu()
{
	int wybor;
	system("cls");
	cout << endl << "MENU";
	cout << endl << "1. Pierwiastek funkcji f(x) = exp(-1.5x) - 0.3x*x";
	cout << endl << "2. Pierwiastek funkcji f(x) = (pi - x*x + sin(x))/sqrt(25 - x)";
	cout << endl << "3. Pierwiastek funkcji f(x) = sin(x)cos(x) + 5x + 1";
	cout << endl << "4. Koniec";
	do
	{
		cout << endl << endl << "Wybor: ";
		cin >> wybor;
	} while (wybor != 1 && wybor != 2 && wybor != 3 && wybor != 4);

	return wybor;
}

