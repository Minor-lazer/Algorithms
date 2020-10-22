#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n)  for(int i=a;i<n;i++)
const int Nmax = 50;
int a[Nmax];

int f(int i, int n){
	 	
	if( n <= 0 || i<0){
		return 0;
	}
	if(i+1 > n) return f(i-1,n);
	int include = a[i]+f(i,n-i-1);
	int exclude = f(i-1,n);
	return max(include,exclude);
}
// Alt solution : 
int maxProfitInRodCutting(int n){
	if(n<=0) return 0;
	int maxValue = INT_MIN;
	for(int i=0;i<n;i++)
		maxValue = max(maxValue, a[i]+maxProfitInRodCutting(n-i-1));
	return maxValue;
}
	 
int main()
{
	 int n,sum; cin>>n;
	 
//	 int a[i];
	 rep(i,0,n) cin>>a[i];
	 
//	 cout<< f(n-1, n)<<endl;
	 cout<<maxProfitInRodCutting(n);
	 return 0;
}

