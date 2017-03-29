// Zad10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

struct uczen
{
	string Imie, Nazwisko;
	int polski, matematyka, fizyka, informatyka;
};

void czyt_dane(int &n, uczen dane[]);
void pisz_dane(int n, uczen dane[]);
void sort_dane(int n, uczen dane[]);
void srednia(int n, uczen dane[], float &srednia_min, float &srednia_max, int &i_min, int &i_max);
float srednia(uczen dane);
void pisz_srednia(int i_min, int i_max, uczen dane[], float srednia_min, float srednia_max);

int main()
{
	uczen dane[20];
	int i_min, i_max, n;
	float srednia_min, srednia_max;

	czyt_dane(n, dane);
	sort_dane(n, dane);
	srednia(n, dane, srednia_min, srednia_max, i_min, i_max);
	pisz_srednia(i_min, i_max, dane, srednia_min, srednia_max);

	_getch();
	return 0;
}

void czyt_dane(int &n, uczen dane[])
{
	cout << "Podaj liczbe uczniow: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << endl << "Wprowadz dane ucznia " << i + 1 << ":"
			<< endl << "  Imie: ";
		cin >> dane[i].Imie;
		cout << "  Nazwisko: ";
		cin >> dane[i].Nazwisko;
		cout << "Wprowadz oceny:"
			<< endl << "  Polski: ";
		cin >> dane[i].polski;
		cout << "  Matematyka: ";
		cin >> dane[i].matematyka;
		cout << "  Fizyka: ";
		cin >> dane[i].fizyka;
		cout << "  Informatyka: ";
		cin >> dane[i].informatyka;
	}
}

void sort_dane(int n, uczen dane[])
{
	uczen tmp;
	bool zmiana;
	cout << endl << endl << "Uczniowie przed posortowaniem:";
	pisz_dane(n, dane);

	for (int i = 0; i < n; i++)
	{
		zmiana = false;
		for (int j = n - 1; j > i; j--)
		{
			if (dane[j].Nazwisko < dane[j - 1].Nazwisko
				|| (dane[j].Nazwisko == dane[j - 1].Nazwisko && dane[j].Imie < dane[j - 1].Imie))
			{
				tmp = dane[j - 1];
				dane[j - 1] = dane[j];
				dane[j] = tmp;
				zmiana = true;
			}
		}

		if (!zmiana)
			break;
	}

	cout << endl << endl << "Uczniowie po posortowaniu:";
	pisz_dane(n, dane);
}

void pisz_dane(int n, uczen dane[])
{
	for (int i = 0; i < n; i++)
		cout << endl << "  " << dane[i].Nazwisko << ", " << dane[i].Imie;
}

float srednia(uczen dane)
{
	return (float)(dane.polski + dane.matematyka + dane.fizyka + dane.informatyka) / 4;
}

void srednia(int n, uczen dane[], float &srednia_min, float &srednia_max, int &i_min, int &i_max)
{
	int i = 1;
	i_min = i_max = 0;
	srednia_min = srednia_max = srednia(dane[0]);
	while (i < n)
	{
		float srednia_ucznia = srednia(dane[i]);
		if (srednia_ucznia < srednia_min)
		{
			i_min = i;
			srednia_min = srednia_ucznia;
		}
		else if (srednia_ucznia > srednia_max)
		{
			i_max = i;
			srednia_max = srednia_ucznia;
		}

		i++;
	}
}

void pisz_srednia(int i_min, int i_max, uczen dane[], float srednia_min, float srednia_max)
{
	cout << endl << endl << "Uczen o najwyzszej sredniej:"
		<< endl << "  " << dane[i_max].Nazwisko << ", " << dane[i_max].Imie << " - " << srednia_max;
	cout << endl << "Uczen o najnizszej sredniej:"
		<< endl << "  " << dane[i_min].Nazwisko << ", " << dane[i_min].Imie << " - " << srednia_min;
}

