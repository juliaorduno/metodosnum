#include <iostream>
#include <cmath>
#include<iomanip>

using namespace std;

double f(double x){
    double ans = 2*pow(x,3)-11.7*pow(x,2)+17.7*x-5;

    return ans;
}

double fprime(double x){
    double ans = 6*pow(x,2)-23.4*x+17.7;
    return ans;
}


int main()
{
    double x,x1,e,fx,fx1,err;
    int iter = 0;
    cout.precision(4);
    cout<<"Enter the initial guess\n";
    cin>>x1;
    cout<<"Enter desired accuracy\n";
    cin>>e; 
    cout <<"x{i}"<<"    "<<"x{i+1}"<<"        "<<"|x{i+1}-x{i}|"<<endl;

    do
    {
        x=x1;
        fx=f(x);
        fx1=fprime(x);
        cout<<"\n"<<fx1<<endl;
        x1=x-(fx/fx1);
        cout<<x<<"     "<<x1<<"           "<<fabs(x1-x)<<endl;
        err = fabs(x1-x);
        cout<<"Error Absoluto "<<err<<"\n"<<endl;
        iter++;
    }while (err>e);
    cout<<"The root of the equation is "<<x1<<endl;
    cout<<"Iterations: "<<iter<<endl;
    return 0;
}
