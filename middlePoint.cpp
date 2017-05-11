#include <iostream>
#include <cmath>

using namespace std;
double x, y, h, xf;

double f(double x, double y){
    return 4*exp(0.8*x)-0.5*y;
}

void middle_point(double xi, double yi, double h, double xf){
    double yj, xj;
    while(xi < xf){
        yj = yi + f(xi,yi)*(h/2);
        xj = xi + h/2;
        yj = yi + f(xj,yj)*h;
        xi += h;
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
    middle_point(x,y,h,xf);
    return 0;
}
