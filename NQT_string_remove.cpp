#include<bits/stdc++.h>
using namespace std;

void dupp(char a[100])
{
	int l=strlen(a);
	
	int prev=0;
	
	for(int curr=0;curr<l;curr++)
	{
		if(a[prev]!=a[curr])
		{
			prev++;
			a[prev]=a[curr];		
		}
		
	
	}
		a[prev+1]='\0';	
	cout<<a<<endl;
}
int main()
{
	char a[100];
	
    cin.getline(a,1000);
	
	dupp(a);
	
	return 0;	
}
