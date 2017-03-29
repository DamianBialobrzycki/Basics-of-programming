// Zad18.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cctype>
#include <string>
#include <conio.h>

using namespace std;

int main()
{
	int x = 1;
	string tekst;
	cout << "Wprowadz tekst:\n";
	getline(cin, tekst);

	int l = tekst.length();

	if (l>0){

		for (int i = 0; i<l; i++)
		{
			if (tekst[i] == ' ')
				x++;
		}
	}
	else x = 0;
	cout << "Ilosc wyrazow wynosi: " << x;
	_getch();
	return 0;
}


