#include <iostream>
#include <cmath>

using namespace std;

double x, y, h, xf;

double f(double x){
    return -2*pow(x,3)+12*pow(x,2)-20*x+8.5;
}

void euler(double xi, double yi, double h, double xf){

    while(xi < xf){
        yi = yi + f(xi)*h;
        xi += h;
        cout << "x= " << xi << ",        y= " <<yi << endl;
    }
}

int main()
{
    x = 0;
    y = 1;
    h = 0.5;
    xf = 4;
    euler(x,y,h, xf);
    return 0;
}
