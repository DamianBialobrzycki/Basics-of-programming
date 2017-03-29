// Zad4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <time.h>
#include <Windows.h>

using namespace std;
int result(int p, int q)
{
	
	int win = 0;

	if (p % 2 == 0)
	{
		switch (q)
		{
		case 2:
		case 4:
		case 5:
			win = p + 3 * q;
			break;
		case 1:
		case 3:
		case 6:
			win = 2 * q;
			break;
		}
	}
	else
	{
		switch (q)
		{
		case 2:
		case 4:
		case 5:
			win = min(p, q) + 4;
			break;
		case 1:
		case 3:
		case 6:
			if (p = q)
				win = 5 * p + 3;
			else
				win = 2 * q + p;
			break;
		}
	}

	if (p == 5 && q == 5)
		win += 5;
	return win;

}
int main()
{
	srand((unsigned)time(NULL));
	char key;
	int p = (double)rand() / (RAND_MAX)* 6 + 1;
	int q = (double)rand() / (RAND_MAX)* 6 + 1;
	do
	{
		// Wersja losujaca
		
		cout << "WERSJA LOSUJACA" << endl;
		cout << "Wylosowano:\np = " << p << "\nq = " << q << endl << endl;

		cout << "Otrzymales " << result(p, q) << "punktow." << endl << endl;

		//Wersja reczna
		cout << "WERSJA RECZNA" << endl << endl;
		cout << "Podaj p: ";
		cin >> p;
		do
		{
			cout << "Podaj q: ";
			cin >> q;
		} while (q<1 || q > 6);
		
		
		cout << endl;

		cout << "Otrzymales " << result(p, q) << "punktow." << endl;

		cout << "\n\nWpisz t by kontynuowac, inny znak konczy petle:" << endl;
		cin >> key;
		system("cls");
	} while (key == 't');
	

	return 0;
}

