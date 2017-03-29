// Zad16.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <random>
#include <ctime>
#include <iomanip>
#include <string>
#include <conio.h>

using namespace std;

void dane(int &n, int &m, int A[][15]);
void pisz_tab(string napis, int n, int m, int A[][15]);
void sort_tab(int n, int m, int A[][15]);

const int n_max = 10;
const int m_max = 15;

int main()
{
	srand(time(NULL));

	int n;
	int m;

	int A[n_max][m_max];

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
	sort_tab(n, m, A);
	pisz_tab("Tablica posortowana", n, m, A);
	_getch();
	return 0;
}

void dane(int &n, int &m, int A[][15])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			A[i][j] = (rand() % 10) + 1;;
		}
	}
}

void pisz_tab(string napis, int n, int m, int A[][15])
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

void sort_tab(int n, int m, int A[][15])
{
	int temp;
	for (int j = 0; j<n; j++)
	{
		for (int k = 1; k <= m; k++)//sortowanie b¹belkowe	
		{
			for (int i = 0; i<m-1; i++)
			{
				if (A[j][i]<A[j][i+1])
				{
					temp = A[j][i];

					A[j][i] = A[j][i+1];

					A[j][i+1] = temp;
				}
			}
		}
	}
}
