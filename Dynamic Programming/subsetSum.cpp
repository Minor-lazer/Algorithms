#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define rep(i,a,n)  for(int i=a;i<n;i++)
const int Nmax = (int) 1e5+5 ;
//int a[Nmax];

bool isSubsetWithSumExist(int a[],int lastIndex , int sum){
	
	
		if(sum == 0) return true;
		if(lastIndex < 0 ){
			return false;
		}
	
	bool include = isSubsetWithSumExist(a,lastIndex , sum - a[lastIndex] );
	bool exclude = isSubsetWithSumExist(a,lastIndex , sum );
	
	return include || exclude ;
}

int main()
{
	
	int t ;
	cin >> t;
	while (t--) {
		
		int n,sum; cin>>n>>sum;
	 
		int a[n];
	 	rep(i,0,n) cin>>a[i];
	 
	 	cout<< isSubsetWithSumExist(a,n-1, sum)<<endl;
	 
	}
	return 0;
}

