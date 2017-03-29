// zad17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>

using namespace std;
bool check(string tekst);
int main()
{
	string tekst;
	getline(cin, tekst, '\n');

	if (check(tekst))
		cout << "Tekst JEST palindromem!" << endl;
	else
		cout << "Tekst NIE JEST palindromem!" << endl;

	_getch();
	return 0;
}
bool check(string tekst)
{

	int j = tekst.length() - 1;

	for (int i = 0; i < tekst.length(); i++)
	{
		cout << "Porownuje " << tekst[i] << " z " << tekst[j] << endl;
		if (tekst[i] == ' ')
			continue;

		else if (tekst[j] == ' ')
		{
			--i;
		}

		else if (tekst[i] != tekst[j])
			return false;
		j--;
	}
	return true;
}