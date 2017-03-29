// Zad14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>


void czytaj_dane(int &n, int X[], int Y[]);
int iloczyn_skalarny(int n, int X[], int Y[]);

const int n_max = 10;

using namespace std;

int main()
{
	int n;
	int X[n_max];
	int Y[n_max];

	do
	{
		cout << "Podaj rozmiar n: ";
		cin >> n;
	} while (n > 10);
	

	czytaj_dane(n, X, Y);
	cout << "\n\nIloczyn skalarny: " << iloczyn_skalarny(n, X, Y) << endl;

	_getch();

	return 0;
}

void czytaj_dane(int &n, int X[], int Y[])
{
	
	for (int i = 0; i < n; i++)
	{
		cout << "Wektor X element " << i << ": ";
		cin >> X[i];
	}
		
	for (int i = 0; i < n; i++)
	{
		cout << "Wektor Y element " << i << ": ";
		cin >> Y[i];
	}
		
}
int iloczyn_skalarny(int n, int X[], int Y[])
{
	int s = 0;

	for (int i = 0; i < n; i++)
	{
		s += X[i] * Y[i];
	}

	return s;
}

