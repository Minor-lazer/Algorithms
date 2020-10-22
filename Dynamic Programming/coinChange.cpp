#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
void solve() {


	// cout << "HI" << endl;
	int noOfCoins, totalSum;
	cin  >> totalSum>> noOfCoins;
	int a[noOfCoins];
	rep(i, 0, noOfCoins) cin >> a[i];


	int dp[totalSum + 1][noOfCoins];
	// m - no of coins, n - totalSum
	memset(dp , 0 , sizeof(dp));

	for (int i = 0; i < noOfCoins; i++) {
		dp[0][i] = 1;
	}
	for (int i = 1; i <= totalSum; i++) {
		for (int j = 0; j < noOfCoins; j++) {

			// if (j == 0) dp[i][j] = 1;

			// if(i<=0 && j>=1) dp[i][j] = 0;

			int include = (i - a[j] >= 0) ? dp[ i - a[j]][j] : 0;
			int exclude = (j >= 1) ? dp[i][j - 1] : 0;
			dp[i][j] = include + exclude;
		}
	}
	for (int i = 0; i <= totalSum; i++) {
		for (int j = 0; j < noOfCoins; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << dp[totalSum][noOfCoins - 1] << endl;
}

int main()
{

	int t ;
	cin >> t;
//	cout << "ok";

	while (t--) {
		solve();
	}
	return 0;
}


