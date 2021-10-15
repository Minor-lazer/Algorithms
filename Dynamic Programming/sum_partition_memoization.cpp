#include<bits/stdc++.h>
using namespace std;

int Subsets(int arr[], int n, int sum,vector<vector<int>> &t)
{
    if (sum == 0)
        return 1;
    if (n <= 0)
        return 0;

    if (t[n][sum] != -1)
        return t[n][sum];

    if (arr[n - 1] > sum)
        t[n][sum] = Subsets(arr, n - 1, sum,t);

    return t[n][sum] = (Subsets(arr, n - 1, sum,t) || Subsets(arr, n - 1, sum - arr[n - 1],t));
}


bool Sum_partition(int arr[], int n){
    int sum=0;
    for(int i=0; i< n; i++)    sum+=arr[i];

    if(sum%2 != 0)    return 0;
    else
    {
        vector<vector<int>> t(n+1,vector<int> (sum/2 + 1,-1));
        return Subsets(arr,n,sum/2,t);
    }
}

int main()
{
    int arr[] = {1,45,3,7,4,11};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (Sum_partition(arr, n))
        cout << "true";
    else
        cout << "false";

    return 0;
}