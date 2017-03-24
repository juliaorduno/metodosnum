// bairstow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>

using namespace std;

//El usuario modifica los valores y tamaño del array a
float a[5] = { 1.0f, -3.0f, 5.0f, -1.0f, -10.0f };
int n = sizeof(a) / sizeof(a[0]);

//Los valores r y s son aleatorios
float r = -1.0f;
float s = -1.0f;
float* c = new float[n - 1];
float* b = new float[n];

float error = 1;
float error_r, error_s;

//Las raíces que se van encontrando se van guardando en un stack
stack <float> roots;

//Para calcular las raíces de una función cuadrática
void cuadratica(float r, float s) {
	float formula = sqrt(pow(r, 2) + 4 * s);
	roots.push((r + formula) / 2);
	roots.push((r - formula) / 2);
}

//calcular la determinante, se usa en el método de cramer
float determinant(float a00, float a01, float a10, float a11) {
	return a00*a11 - a10*a01;
}

//Sirve para encontrar los valores de delta r y delta s
float *cramer(float a00, float a01, float a10, float a11, float b0, float b1) {
	float det, delta_r, delta_s;
	det = determinant(a00, a01, a10, a11);
	delta_r = determinant(b0, a01, b1, a11) / det;
	delta_s = determinant(a00, b0, a10, b1) / det;
	float arr[2] = { delta_r, delta_s };
	return arr;
}

//Error iterativo 
float errorPorcentual(float x, float y) {
	return fabs(x / y) * 100;
}


void division_sintetica(float r, float s) {
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
	float c2, c3, c1, b1, b0;

	//Sistema de ecuaciones:
	//c2*DELTAr + c3*DELTAs = –b1
	//c1*DELTAr + c2*DELTAs = –b0
	c2 = c[(n - 1) - 2];
	c3 = c[(n - 1) - 3];
	c1 = c[(n - 1) - 1];
	b1 = b[n - 2];
	b0 = b[n - 1];

	//Cramer sirve para encontrar las incógnitas del sistema de ecuaciones
	float *deltas = cramer(c2, c3, c1, c2, -b1, -b0);

	//Modificar r y s, calcular errores iterativos porcentuales hasta que ambos sean menor al error estimado
	r = r + deltas[0];
	s = s + deltas[1];

	error_r = errorPorcentual(deltas[0], r);
	error_s = errorPorcentual(deltas[1], s);

	if (error_r > error && error_s > error) {
		bairstow();
	}

	//Calcular las raíces dependiendo del grado de la función restante
	else {
		cuadratica(r, s);

		n = n - 2;
		for (int i = 0; i < n; i++) {
			a[n - i] = b[n - i];
		}

		if (n >= 4) {
			bairstow();
		}
		else if (n == 3) {
			cuadratica(r, s);
			return;
		}
		else {
			roots.push(-(a[1] / a[0]));
			return;
		}
	}
}

int main()
{

	bairstow();
	int degree = roots.size();
	for (int i = 0; i < degree; i++) {
		cout << "Root " << i << "= " << roots.top() << endl;
		roots.pop();
	}

	return 0;
}
