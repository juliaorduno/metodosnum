// bairstow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>

using namespace std;

//El usuario modifica los valores y tamaño del array a
double a[4] = { 1.0f, -4.0f, 5.25f, -2.5f };
int n = sizeof(a) / sizeof(a[0]);
int it = 0;

//Los valores r y s son aleatorios
double r = -0.5f;
double s = 0.5f;
double* c = new double[n - 1];
double* b = new double[n];

double error = 1;
double error_r, error_s;

struct complex {
	double r;
	double i;
};

//Las raíces que se van encontrando se van guardando en un stack
stack <complex*> roots;


//Para calcular las raíces de una función cuadrática
void cuadratica(double a, double b, double c, complex *r1, complex *r2) {
	double det = pow(b, 2) - 4 * a * c;
	if (det < 0) {
		r1->r = -b / 2;
		r1->i = sqrt(-det) / 2 / a;
		r2->r = -b / 2;
		r2->i = -sqrt(-det) / 2 / a;
	}
	else {
		r1->r = (-b + sqrt(det)) / 2 / a;
		r1->i = 0;
		r2->r = (-b - sqrt(det)) / 2 / a;
		r2->i = 0;
	}
}

//calcular la determinante, se usa en el método de cramer
double determinant(double a00, double a01, double a10, double a11) {
	return a00*a11 - a10*a01;
}

//Sirve para encontrar los valores de delta r y delta s
double *cramer(double a00, double a01, double a10, double a11, double b0, double b1) {
	double det, delta_r, delta_s;
	det = determinant(a00, a01, a10, a11);
	delta_r = determinant(b0, a01, b1, a11) / det;
	delta_s = determinant(a00, b0, a10, b1) / det;
	double arr[2] = { delta_r, delta_s };
	return arr;
}

//ERROR PARCIAL2
double errorPorcentual(double x, double y) {
	return fabs(x / y) * 100;
}


void division_sintetica(double r, double s) {
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			b[i] = a[i];
			c[i] = b[i];
		}
		else if (i == 1) {
			b[i] = a[i] + r*b[i - 1];
			c[i] = b[i] + r*c[i - 1];
		}
		else if (i == n - 1) {
			b[i] = a[i] + r*b[i - 1] + s*b[i - 2];

		}
		else {
			b[i] = a[i] + r*b[i - 1] + s*b[i - 2];
			c[i] = b[i] + r*c[i - 1] + s*c[i - 2];
		}
	}
}

void bairstow() {
	division_sintetica(r, s);

	//Son valores establecidos por el método de bairstow para aplicarlos en el método de cramer
	double c2, c3, c1, b1, b0;

	//Sistema de ecuaciones:
	//c2*DELTAr + c3*DELTAs = –b1
	//c1*DELTAr + c2*DELTAs = –b0
	c2 = c[(n - 1) - 2];
	c3 = c[(n - 1) - 3];
	c1 = c[(n - 1) - 1];
	b1 = b[n - 2];
	b0 = b[n - 1];

	//Cramer sirve para encontrar las incógnitas del sistema de ecuaciones
	double *deltas = cramer(c2, c3, c1, c2, -b1, -b0);

	//Modificar r y s, calcular errores iterativos porcentuales hasta que ambos sean menor al error estimado
	r = r + deltas[0];
	s = s + deltas[1];

	error_r = errorPorcentual(deltas[0], r);
	error_s = errorPorcentual(deltas[1], s);

	it++;
	if (error_r > error && error_s > error) {

		bairstow();
	}

	//Calcular las raíces dependiendo del grado de la función restante
	else {
		complex *r1 = new complex;
		complex *r2 = new complex;
		cuadratica(1.0, -r, -s, r1, r2);
		roots.push(r1);
		roots.push(r2);

		n = n - 2;
		for (int i = 0; i < n; i++) {
			a[n - i] = b[n - i];
		}

		if (n >= 4) {
			bairstow();
		}
		else if (n == 3) {
			complex *r1 = new complex;
			complex *r2 = new complex;
			cuadratica(a[0], a[1], a[2], r1, r2);
			roots.push(r1);
			roots.push(r2);
			return;
		}
		else {
			complex *r = new complex;
			r->r = -a[1] / a[0];
			r->i = 0;
			roots.push(r);
			return;
		}
	}
}

int main()
{

	bairstow();
	int degree = roots.size();
	for (int i = 0; i < degree; i++) {
		cout << "Root " << i << "= " << roots.top()->r << " + " << roots.top()->i << "i" << endl;
		roots.pop();
	}

	cout << "Cociente" << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	cout << "\nIteraciones= " << it;

	return 0;
}
