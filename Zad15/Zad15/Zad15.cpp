// Zad15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <conio.h>
#include <iomanip>


using namespace std;

void dane(int &n, int &m, int A[][5]);
void pisz_tab(string napis, int n, int m, int A[][5]);
void mat_trans(int n, int m, int A[][5], int AT[][8]);
void pisz_tab_trans(string napis, int n, int m, int AT[][8]);

const int n_max = 8;
const int m_max = 5;

int main()
{
	srand(time(NULL));

	int n;
	int m;

	int A[n_max][m_max];
	int AT[m_max][n_max];
	
	do
	{
		cout << "Podaj n: ";
		cin >> n;
	} while (n > n_max);
	
	do
	{
		cout << "Podaj m: ";
		cin >> m;
	} while (m > m_max);

	dane(n, m, A);
	pisz_tab("Tablica pierwotna", n, m, A);
	mat_trans(n, m, A, AT);
	pisz_tab_trans("Tablica transportowana", n, m, AT);

	_getch();
	return 0;
}

void dane(int &n, int &m, int A[][5])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			A[i][j] = (rand() % 21) - 10;;
		}
	}
}

void pisz_tab(string napis, int n, int m, int A[][5])
{
	cout << napis << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(3) << A[i][j] << " ";
		}
		cout << endl;
	}
}

void mat_trans(int n, int m, int A[][5], int AT[][8])
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			AT[i][j] = A[j][i];
		}
	}
			
	
}

void pisz_tab_trans(string napis, int n, int m, int AT[][8])
{
	cout << napis << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << setw(3) << AT[i][j] << " ";
		}
		cout << endl;
	}
}
