//Taylor series using Horner's Rule
//e^x= 1+(x/1)+(x^2/2!)+(x^3/3!)+......n terms


#include<iostream>
using namespace std;

double e(int,int);

int main()
{ int x,n;
  double z;
  cout<<"Enter values of x and n: ";
  cin>>x>>n;
  z=e(x,n);
  cout<<z;
  return 0;
}                                       
double e(int x, int n)
{
static double s;
if(n==0)
return s;
s=1+x*s/n;
return e(x,n-1);
}




