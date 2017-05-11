#include <iostream>
#include <cmath>

using namespace std;
double x, y, h, xf;

double f(double x, double y){
    return 4*exp(0.8*x)-0.5*y;
}

double predictor(double xi, double yi, double h){
    return yi + f(xi,yi)*h;
}

double corrector(double xi, double yi, double xj, double yj, double h){
    return yi + (f(xi,yi)+f(xj,yj))*(h/2);
}

void heun(double xi, double yi, double h, double xf){
    double yj, xj;
    while(xi < xf){
        yj = predictor(xi,yi,h);
        xj = xi + h;
        yj = corrector(xi, yi, xj, yj, h);
        xi = xj;
        yi = yj;
        cout << "x= " << xi << ",        y= " <<yi << endl;
    }
}

int main()
{
    x = 0;
    y = 2;
    h = 1;
    xf = 4;
    heun(x,y,h, xf);
    return 0;
}
