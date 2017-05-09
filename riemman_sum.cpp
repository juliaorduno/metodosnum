
#include <cmath>
#include <iostream>

using namespace std;

int n;
double a, b, sum, error;
double integral = 1.64053;

double f(double x) {
	return 0.2 + 25 * x - 200 * pow(x, 2) + 675 * pow(x, 3) - 900 * pow(x, 4) + 400 * pow(x, 5);
}

double formula_xi(int i, double a, double diff) {
	return a + i*diff;
}

double riemman_sum(int n, double a, double b) {
	double diff = (b - a) / n;
	double sum = 0;
	double xi, xim;
	for (int i = 1; i <= n; i++)
	{
		xi = formula_xi(i, a, diff);
		xim = formula_xi(i-1, a, diff);
		sum += f(xi)*(xi - xim);
	}
	return sum;
}

int main()
{
	n = 2;
	a = 0;
	b = 0.8;

	sum = riemman_sum(n, a, b);
	error = (integral - sum) / integral * 100;
	cout << "Integral: " << sum << endl;
	cout << "Error: " << error << endl;

    return 0;
}

