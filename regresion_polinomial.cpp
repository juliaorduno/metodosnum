// regresion_polinomial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void forward_elimination(double **A, double b[], int n) {
	double factor;
	for (int k = 0; k < (n-1); k++) {
		for (int i = k + 1; i < n; i++) {
			factor = A[i][k] / A[k][k];
			for (int j = k+1; j < n; j++) {
				A[i][j] = A[i][j] - factor*A[k][j];
			}
			b[i] = b[i] - factor*b[k];
		}
	}
}

void back_sustitution(double **A, double b[], int n, double solution[]) {
	double sum;
	solution[n - 1] = b[n - 1] / A[n - 1][n - 1];
	for (int i = n - 2; i > -1; i--) {
		sum = 0;
		for (int j = i + 1; j < n; j++) {
			sum = sum + A[i][j] * solution[j];
		}
		solution[i] = (b[i]-sum) / A[i][i];
	}
}

double* regresion_polinomial(int n, int m, double x[], double y[]){
	int matrix_size = m + 1;

	double **A, *b, sx, sxy;
	A = new double*[matrix_size];
	b = new double[matrix_size];
	
	for (int i = 0; i < matrix_size; i++) {	
		A[i] = new double[matrix_size];
	}
	
	for (int i = 0; i < matrix_size; i++)
	{
		for (int j = 0; j < matrix_size; j++)
		{
			sx = 0;
			if (i == 0 && j == 0)
				sx = n;
			else {
				for (int k = 0; k < n; k++) 
					sx += pow(x[k], (i + j));
			}
			
			A[i][j] = sx;
		}
		
		sxy = 0;
		for (int j = 0; j < n; j++)
			sxy += pow(x[j], i)*y[j];
		b[i] = sxy;
		
	}
	
	forward_elimination(A, b, matrix_size);

	double *solution = new double[matrix_size];

	back_sustitution(A, b, matrix_size, solution);

	double sr, sy, syx, st, m_y, r;
	m_y = b[0] / n;
	sr = st = 0;
	for (int i = 0; i < n; i++) {
		sy = y[i];
		for (int j = 0; j < matrix_size; j++) {
			sy -= solution[j] * pow(x[i], j);
		}
		sr += pow(sy,2);
		st += pow((y[i] - m_y), 2);
	}
	syx = sqrt(sr/(n-matrix_size));
	r = sqrt((st - sr) / st);

	cout << "Error estandar: " << syx << endl;
	cout << "Coeficiente de correlacion: " << r << endl;

	return solution;

}

int main() {
	ifstream x_values("x_values.txt");
	ifstream y_values("y_values.txt");

	int n, m;
	cout << "Número de datos: ";
	cin >> n;
	cout << "Grado: ";
	cin >> m;

	double *xval = new double[n], 
		   *yval = new double[n],
		   *aval;
	int i = 0;

	for (int i = 0; x_values && y_values && i < n; i++) {
		x_values >> xval[i];
		y_values >> yval[i];
	}

	aval = regresion_polinomial(n, m, xval, yval);
	for (int i = 0; i < (m+1); i++)
	{
		cout << "a" << i << ": " << aval[i] << endl;
	}

	cout << "y = ";
	for (int i = m; i >= 0; i--)
	{
		cout << aval[i] << "x" << i << " + ";
	}
	return 0;
}

