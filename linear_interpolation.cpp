#include <iostream>
#include <cmath>
#include<iomanip>

using namespace std;


int main()
{
	double x1 = 1,
		x2 = 4,
		x = 2,
		y1 = 0,
		y2 = 1.386294,
		y = 0;

	y = y1 + ((y2 - y1) / (x2 - x1))*(x - x1);
	// y = b + mx

	cout << "y= " << ((y2 - y1) / (x2 - x1)) << "x + " << y1<<endl;
	cout << "Y value evaluated in x = " << x << " is " << y << endl;
    return 0;
}

