// jacobi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <iostream>

using namespace std;

float a[3][3] = { { 3.0f,-0.1f,-0.2f },{ 0.1f,7.0f,-0.3f },{ 0.3f,-0.2f,10.0f } },
	  b[3] = { 7.85f, -19.3f, 71.4f };
float x1, x2, x3, error, e1, e2, e3, t1, t2, t3;
int i;


float f(float b, float a1, float x1, float a2, float x2, float a3) {
	return (b - a1*x1 - a2*x2) / a3;
}

float err(float ec[3], float b) {
	return fabs(ec[0] * x1 + ec[1] * x2 + ec[2] * x3 - b);
}

int main()
{
	x1 = x2 = x3 = 0.0f;
	error = 0.0001f;
	i = 0;

	do {
		t1 = x1;
		t2 = x2;
		t3 = x3;

		x1 = f(b[0], a[0][1], t2, a[0][2], t3, a[0][0]);
		x2 = f(b[1], a[1][0], t1, a[1][2], t3, a[1][1]);
		x3 = f(b[2], a[2][0], t1, a[2][1], t2, a[2][2]);

		e1 = err(a[0], b[0]);
		e2 = err(a[1], b[1]);
		e3 = err(a[2], b[2]);

		i++;

	} while (e1 > error || e2 > error || e3 > error);

	cout << "x1 = " << x1 << endl;
	cout << "x2 = " << x2 << endl;
	cout << "x3 = " << x3 << endl;
	cout << "Iteraciones = " << i << endl;
}