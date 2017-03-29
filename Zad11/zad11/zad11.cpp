// zad11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Kolo.h"
#include <conio.h>

using namespace std;

void Odleglosc(Kolo K_1, Kolo K_2);

int main()
{

	Kolo bialy(5, 5, 5), czerwony(5, 5, 3);

	cout << "Dane bialy:" << endl;
	bialy.Podaj_Pole_Obwod();
	cout << endl;
	cout << "Dane czerwony:" << endl;
	czerwony.Podaj_Pole_Obwod();
	cout << endl;
	Odleglosc(bialy, czerwony);

	_getch();
	return 0;
}

void Odleglosc(Kolo K_1, Kolo K_2)
{
	double l = sqrt((K_1.Podaj_x() - K_2.Podaj_x())*(K_1.Podaj_x() - K_2.Podaj_x()) + (K_1.Podaj_y() - K_2.Podaj_y())*(K_1.Podaj_y() - K_2.Podaj_y()));

	cout << "Odleglosc miedzy srodkami kol wynosi: " << l << endl;
	
	double r1 = K_1.Podaj_r();
	double r2 = K_2.Podaj_r();


	if (l > r1 + r2)
		cout << "Kola rozlaczne zewnetrznie." << endl;
	if (l == r1 + r2)
		cout << "Kola styczne zewnetrznie." << endl;
	if (fabs(r1 - r2) < l && fabs(r1 + r2) > l)
		cout << "Kola przecinajace sie." << endl;
	if (l == fabs(r1 - r2))
		cout << "Kola styczne wewnetrznie." << endl;
	if (l < fabs(r1 - r2))
		cout << "Kola rozlaczne wewnetrznie." << endl;
	if (K_1.Podaj_x() == K_2.Podaj_x() && K_1.Podaj_y() == K_2.Podaj_y())
		cout << "kola o wspolnym srodku" << endl;
}

