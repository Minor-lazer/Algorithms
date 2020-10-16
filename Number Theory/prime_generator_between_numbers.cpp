#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define mod 1000000007
using namespace std;
bool isPrime(int k){
    for(int i = 2 ; i*i <= k ; i++)
        if(k%i == 0)
            return false;
    return true;
}
void print(int m, int n){
    if(m == 1)
        m++;
    for(int i = m ; i <= n ; i++)
        if(isPrime(i))
            cout << i << endl;
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int m, n;
        cin >> m >> n;
        print(m, n);
    }
}
