// Zad13.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <time.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>
#include <Windows.h>

using namespace std;

void gotoxy(int x, int y);

class Punkt
{
protected:
	int x, y, kolor;
	char znak;

public:
	Punkt(int _x, int _y, int _kolor, char _znak) : x(_x), y(_y), kolor(_kolor), znak(_znak)
	{}

	~Punkt()
	{
		cout << "\nDestruktor likwiduje punkt w kolorze " << kolor << endl;
	}

	void Rysuj()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), kolor);
		gotoxy(x, y);
		cout << znak;
	}
};

class Kwadrat : public Punkt
{
	int a, start_x, start_y;

public:
	Kwadrat(int _x, int _y, int _a, int _kolor, int _znak) : Punkt(_x, _y, _kolor, _znak), a(_a), start_x(_x), start_y(_y)
	{
	}

	~Kwadrat()
	{
		cout << "\nDestruktor likwiduje kwadrat w kolorze " << kolor << endl;
	}

	void RysujKolejny()
	{
		Rysuj();
		if (y == start_y && x < start_x + a - 1)
			x++;
		else if (x == start_x + a - 1 && y < start_y + a - 1)
			y++;
		else if (y == start_y + a - 1 && x > start_x)
			x--;
		else if (x == start_x && y > start_y)
			y--;
	}

	void RysujCaly()
	{
		for (int i = 0; i < 4 * a - 4; i++)
		{
			RysujKolejny();
			Sleep(200);
		}
	}
};

int main()
{
	int a = 10;
	Kwadrat K[3] =
	{
		Kwadrat(0, 0, a, 3, '1'),
		Kwadrat(80 / 3, 0, a, 5, '2'),
		Kwadrat(80 / 3 * 2, 0, a, 10, '3')
	};

	for (int i = 0; i < 4 * a - 4; i++)
	{
		for (int j = 0; j < 3; j++)
			K[j].RysujKolejny();
		Sleep(200);
	}

	_getch();
	return 0;
}

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}


