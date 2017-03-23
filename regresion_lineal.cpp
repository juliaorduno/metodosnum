// regresion_lineal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <cmath>
#include <iostream>

using namespace std;

double *regresion_lineal(int n, string t_file, string c_file) {

	std::ifstream tempFile(t_file);
	std::ifstream consFile(c_file);

	double sxy, sx, sy, sx2, x, y;
	double *xval = new double[n];
	double *yval = new double[n];
	sxy = sx = sy = sx2 = x = y = 0;

	int i = 0;
	while (tempFile >> x && consFile >> y) {
		sx += x;
		sy += y;
		sx2 += x*x;
		sxy += x*y;

		xval[i] = x;
		yval[i] = y;
		i++;
	}

	double a0, a1, sr, error, my, mx, st, r, stx, sty;
	my = sy / n;
	mx = sx / n;
	sr = st = stx = sty = 0;
	a1 = (n*sxy - sx*sy) / (n*sx2 - (pow(sx, 2)));
	a0 = (my) - (a1*(mx));

	for (int i = 0; i < n; i++) {
		sr += pow((yval[i] - a0 - a1*xval[i]), 2);
		st += (yval[i] - my)*(xval[i] - mx);
		stx += pow((xval[i] - mx),2);
		sty += pow((yval[i] - my),2);
	}

	error = sqrt(sr / (n - 2));
	r = st/(sqrt(stx)*sqrt(sty));

	cout << "y = " << a0 << " +"  << a1 << "x" << endl;
	cout << "Error estandar= " << error << endl;
	cout << "Coeficiente de correlacion= " << r << endl;

	return new double[2]{ a0,a1 };
}

int main()
{
	double *ans = regresion_lineal(15, "temp.txt", "cons.txt");
}



