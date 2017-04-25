// interpolacion_newton.cpp : Defines the entry point for the console application.
//
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int n;
double *b, error_relativo;

//formula = (fx[0] - fx[1]) / (x[0] - x[1])
void newton(double fx[], double x[], int n) {
	for (int i = 0; i < n; i++)
	{
		b[i] = fx[0];
		for (int j = 0; j < n; j++)
		{
			fx[j] = (fx[j+1] - fx[j]) / (x[j+i+1] - x[j]);
		}
	}
}

double evaluate(double x, double fx[], double xi[], int n) {
	double answer = b[0];
	double term;
	for (int i = 1; i < n; i++)
	{
		term = b[i];
		for (int j = 0; j < i; j++)
		{
			term *= (x - xi[j]);
		}
		answer += term;
	}
	return answer;
}

void calculate_error(double real, double aprox) {
	error_relativo = fabs((real - aprox) / real);
	cout << "Error relativo: " << error_relativo << endl;
	cout << "Error absoluto: " << fabs(real - aprox) << endl;
}


int main()
{
	setprecision(6);
	n = 4;
	double fx[] = {6,19,99,291};
	double x[] = {2,3,5,7};
	b = new double[n];

	newton(fx, x, n);
	for (int i = 0; i < n; i++)
	{
		cout << "b" << i << "= " << b[i] << endl;
	}

	double toEvaluate = 4;

	double answer = evaluate(toEvaluate, fx, x, n);
	cout << "Evaluating in x= " << toEvaluate<< endl;
	cout << "Answer= " << answer << endl;


    return 0;
}

