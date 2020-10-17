#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	
	char a[100][100];
	
	cin.get();
	
	for(int i=0;i<n;i++)
	{
		cin.getline(a[i],1000);
	}
	
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
	}
	
	return 0;
}
