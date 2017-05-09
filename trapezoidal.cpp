
#include <cmath>
#include <iostream>

using namespace std;

double a, b, error, answer;
int n;
double integral = 1.64053;

double f(double x) {
	return 0.2 + 25 * x - 200 * pow(x, 2) + 675 * pow(x, 3) - 900 * pow(x, 4) + 400 * pow(x, 5);
}

double formula_xi(int i, double a, double h) {
	return a + i*h;
}

double trapezoidal(int n, double a, double b) {
	double h = (b - a) / n;
	double sum = 0;
	double xi, fx0, fxn, ans;
	for (int i = 1; i < n; i++)
	{
		xi = formula_xi(i, a, h);
		sum += f(xi);
	}

	fx0 = f(formula_xi(0, a, h));
	fxn = f(formula_xi(n,a,h));
	ans = (h/2)*(fx0 + 2*sum + fxn);

	return ans;
}

int main()
{
	n = 1;
	a = 0;
	b = 0.8;

	answer = trapezoidal(n, a, b);
	error = (integral - answer) / integral * 100;
	cout << "Integral: " << answer << endl;
	cout << "Error: " << error << endl;
    return 0;
}

