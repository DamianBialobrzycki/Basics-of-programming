// Zad5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

const int Esc = 27;

int main()
{
	char key;
	char category;

	int hours = 0;
	int overtime = 0;
	int rate = 0;

	double profitNetto = 0;
	double profitBrutto = 0;
	double tax = 0;

	do
	{
		system("cls");

		do
		{
			cout << "Podaj swoja kategorie zaszeregowania (A-D): ";
			cin >> category;
		} while (category < 64 || category > 68);
		
		do
		{
			cin.clear();
			cin.sync();
			cout << "Podaj ilosc przepracowanych godzin: ";
			cin >> hours;
		} while (cin.fail());
		

		switch (category)
		{
			case 'A':
				rate = 15;
				break;
			case 'B':
				rate = 25;
				break;
			case 'C':
				rate = 30;
				break;
			case 'D':
				rate = 35;
				break;
		}

		if (hours > 40)
		{
			overtime = hours - 40;
		}

		profitNetto = 40 * rate + overtime * (2 * rate);
		
		if (profitNetto <= 700)
			tax = 0.15;
		else if (profitNetto >= 701 && profitNetto <= 1200)
			tax = 0.20;
		else
			tax = 0.25;

		profitBrutto = profitNetto - profitNetto * tax;

		system("cls");
		cout << "Twoj zarobek NETTO: " << profitNetto << endl;
		cout << "Twoj zarobek BRUTTO: " << profitBrutto << endl;
		cout << endl;

		cout << "Aby wyjsc z programu wcisnij Esc, w przeciwnym wypadku wcisnij inny klawisz.";
		key = _getch();
	} while (key != Esc);
	
	return 0;
}

