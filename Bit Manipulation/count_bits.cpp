#include<iostream>
using namespace std;

int countBits(int n)
{
	int count=0;
	while(n)
	{
		count++;
		n=n>>1;
	}
	return count;
}


 main()
{
	int n;
	cout<<"Enter any Number"<<endl;
	cin>>n;
	cout<<"Number of bits : "<<countBits(n);
}