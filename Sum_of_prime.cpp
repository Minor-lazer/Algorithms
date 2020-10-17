#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int n)
{
	if(n==1)
	{
		return false;
	}
	
	else
	{
		for(int i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				return false;			
			}
		}
	}
	
	return true;
}

void primeSum(int l,int r)
{
	int sum=0;
	for(int i=r;i>=l;i--)
	{
		bool result=checkPrime(i);
		
		if(result)
		{
			sum=sum+i;
		}
	}
	
	cout<<sum<<endl;
}
int main()
{
  	int l,r;
  	
  	cin>>l>>r;
  	
  	primeSum(l,r);
  	
  	return 0;
}
