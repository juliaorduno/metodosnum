#include <iostream>
#include <cmath>
#include<iomanip>

using namespace std;

double f(double x){
    double ans = exp(-x)-x;
    return ans;
}

int main()
{
    double x,x0,x1,e,fx0,fx1,err;
    int iter = 0;
    cout.precision(4);
    cout<<"Enter the initial guesses\n";
    cout<<"x0 = ";
    cin>>x;
    cout<<"x1 = ";
    cin>>x0;
    cout<<"Enter desired accuracy\n";
    cin>>e;
    cout <<"x{i-1}"<<"    "<<"x{i}"<<"        "<<"x{i+1}          "<<endl;

    do
    {
        x1 = x0;
        x0=x;
        fx0=f(x0);
        fx1 = f(x1);
        x = x1-((fx1*(x0-x1))/(fx0-fx1));
        err = fabs(x-x0);
        cout<<x0<<"     "<<x1<<"           "<<x<<endl;
        cout<<"Error Absoluto "<<err<<"\n"<<endl;
        iter++;
    }while (err>e);
    cout<<"The root of the equation is "<<x1<<endl;
    cout<<"Iterations: "<<iter<<endl;
    return 0;
}
