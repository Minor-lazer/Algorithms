#include<bits/stdc++.h>
using namespace std;

int main()
{
//fill the code;
	int n;
	cin >> n;
	int arr1[n], arr2[n];
	int i;
	for(i = 0; i < n ; i++)
		{
			cin >> arr1[i];
		}
	for(i = 0; i < n ; i++)
		{
			cin >> arr2[i];
		}

	sort(arr1, arr1 + n);
	sort(arr2, arr2 + n, greater<int>());
	int sum = 0;
	for(i = 0; i < n ; i++)
		{
			sum = sum + (arr1[i] * arr2[i]);
		}
	cout << sum;
	return 0;
}
