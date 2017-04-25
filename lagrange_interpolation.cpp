#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int n;
double fxi[] = {6,19,99,291};
double xi[] = {2,3,5,7};
double x;

double lagrange_interpolation(double xi[], double fxi[], int n, int x){
    double sum = 0;
    double product;
    for(int i=0; i<n; i++){
        product = 1;
        for(int j=0; j<n; j++){
            if(j != i)
                product *= (x-xi[j])/(xi[i]-xi[j]);
        }
        sum += product*fxi[i];
    }
    return sum;
}

int main()
{
    n = 4;
    x = 4;


    double answer = lagrange_interpolation(xi, fxi, n, x);
    cout << "Evaluating in x = " << x << endl;
    cout << "Answer: " << answer << endl;
    return 0;
}
