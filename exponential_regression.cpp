// exponential_regression.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

void regresion_exponencial(int n, string t_file, string c_file) {

	ifstream xFile(t_file);
	ifstream yFile(c_file);

	double sxy, sx, sy, sx2, x, y;
	double *xval = new double[n];
	double *yval = new double[n];
	sxy = sx = sy = sx2 = x = y = 0;

	int i = 0;
	while (xFile >> x && yFile >> y) {
		//x = log(x);
		y = log(y);
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
	a0 = (my)-(a1*(mx));

	for (int i = 0; i < n; i++) {
		sr += pow((yval[i] - a0 - a1*xval[i]), 2);
		st += (yval[i] - my)*(xval[i] - mx);
		stx += pow((xval[i] - mx), 2);
		sty += pow((yval[i] - my), 2);
	}

	error = sqrt(sr / (n - 2));
	r = st / (sqrt(stx)*sqrt(sty));

	cout << "a0 = " << a0 << endl << "a1 = " << a1 << endl;
	cout << "Error estandar= " << error << endl;
	cout << "Coeficiente de correlacion= " << r << endl;
	//a0 = a, a1 = B
	double a = exp(a0);
	cout << "y= " << a << "e" << a1 << "x"<<endl;

	double evaluation = a*exp(a1 * 9);
	cout << "Evaluation= " << evaluation << endl;
}

int main()
{
	regresion_exponencial(10, "x.txt", "y.txt");
}

