#pragma once

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

class Kolo
{ 
	private:
		double x, y, r;
		double Pole()
		{
			return M_PI * r * r;
		}
		double Obwod()
		{
			return 2 * M_PI * r;
		}
	public:
		double Podaj_x(){ return x; }
		double Podaj_y(){ return y; }
		double Podaj_r(){ return r; }

		void Podaj_Pole_Obwod()
		{
			cout << "Pole: " << Pole() << endl;
			cout << "Obwód: " << Obwod() << endl;
		}

		Kolo(double _x, double _y, double _r) : x(_x), y(_y), r(_r){};

		~Kolo()
		{
			cout << "\nDestruktor likwiduje kolo o promieniu " << r << endl;
		};

};

