
#include <cmath>
#include <iostream>

using namespace std;

double a, b, error, answer;
int n;

double f(double x) {
	return pow(x,2);
}

double formula_xi(int i, double a, double h) {
	return a + i*h;
}

double simpson_rule1_3(double a, double b, int n) {
    double h = (b - a) / n;
    double sum_i = 0;
    double sum_j=0;
    double xi, fx0, fxn;
    for(int i=1; i<n; i+=2){
        xi = formula_xi(i,a,h);
        sum_i += f(xi);
    }

    for(int j=2; j<n-1; j+=2){
        xi = formula_xi(j,a,h);
        sum_j += f(xi);
    }
    cout << 4*sum_i + 2*sum_j ;
    fx0 = f(formula_xi(0,a,h));
    fxn = f(formula_xi(n,a,h));

    double i = h/3*(fx0 + 4*sum_i + 2*sum_j + fxn);

    return i;
}


int main()
{
    n = 4;
    a = 1;
	b = 5;

    answer = simpson_rule1_3(a,b,n);
    cout << "Answer 1/3: " << answer << endl;
    return 0;
}

