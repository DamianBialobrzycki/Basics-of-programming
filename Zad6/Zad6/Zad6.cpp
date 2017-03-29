// Zad6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>

using namespace std;

int silnia(int liczba)
{
	int silnia = 1;
	for (int i = 1; i <= liczba; i++)
		silnia *= i;

	return silnia;
}

int wynik(int silniaN, int silniaK, int silniaNK)
{
	int wynik = 0;
	wynik = silniaN / (silniaK * silniaNK);

	return wynik;
}

int main()
{
	int n = 0, k = 0, m = 0, nk = 0, sn = 1, sk = 1, snk = 1;
	cout << "Podaj ilosc elementow:";
	cin >> n;
	cout << "Podaj ile elementow ma znalezc sie w zbiorze:";
	cin >> k;

	// Sposob 1. Bez uzycia funkcji.
	for (int i = 1; i <= n; i++)
		sn *= i;

	for (int i = 1; i <= k; i++)
		sk *= i;

	nk = n - k;

	for (int i = 1; i <= nk; i++)
		snk *= i;
	m = sn / (sk * snk);

	cout << "\n\nSposob 1. Bez uzycia funckji." << endl;
	cout << "Mozna utworzyc " << m << " zbiorow." << endl;


	// Sposob 2. Uzycie 2 funkcji.
	sn = silnia(n);
	sk = silnia(k);
	snk = silnia(n - k);

	cout << "\n\n\nSposob 2. Uzycie 2 funkcji" << endl;
	cout << "Mozna utworzyc " << wynik(sn, sk, snk) << " zbiorow." << endl;
	_getch();
	return 0;
}

