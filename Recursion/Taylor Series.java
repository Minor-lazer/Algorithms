#include<iostream>
#include<bits/stdc++.h>
using namespace std;
double e(double  x,double n)
{
    static double s = 1;
    if(n == 0)
    {
        return s;
    }
    else{
        s = 1 + (x/n)*s;
        return e(x,n-1);
    }
}
int main()
{
    double x,n;
    cout<<"Enter the power and the exponent : ";
    cin>>x>>n;
    cout<<" Result ";
    cout<<e(x,n);
    return 0;
}
