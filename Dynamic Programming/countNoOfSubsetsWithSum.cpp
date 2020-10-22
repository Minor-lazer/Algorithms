#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n)  for(int i=a;i<n;i++)
const int Nmax = 50;
int a[Nmax];

int dp[Nmax][Nmax];
bool v[Nmax][Nmax];

int countSubSetSum(int indexOfLastElement, int sum){
	 	
	if(indexOfLastElement < 0){
		if(sum==0)  return 1;
		else return 0;
		
	}
	if(v[indexOfLastElement][sum])
		return dp[indexOfLastElement][sum];
	
	v[indexOfLastElement][sum] = 1;
	
	dp[indexOfLastElement][sum] = countSubSetSum(indexOfLastElement-1, sum - a[indexOfLastElement]) + countSubSetSum(indexOfLastElement-1, sum);
//	int includeLast = countSubSetSum(indexOfLastElement-1, sum - a[indexOfLastElement]);5

//	int excludeLast = countSubSetSum(indexOfLastElement-1, sum );

//	return includeLast + excludeLast;
	return dp[indexOfLastElement][sum];
}

	 
int main()
{
	 int n,sum; cin>>n>>sum;
	 
//	 int a[i];
	 rep(i,0,n) cin>>a[i];
	 
	 cout<< countSubSetSum(n-1, sum)<<endl;
	 
	 return 0;
}

