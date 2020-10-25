/*
*
*Problem Link : https://leetcode.com/problems/longest-valid-parentheses/submissions/
*Platform: leetcode
*Status: correct
*Author: Mayukh Chakrabarti
*
*/

#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;

using namespace std;

class Solution{
    public:
    int longestValidParentheses(string s) {
        int cnt = 0; 
        vector<int> dp(s.size()+1, 0);
        
        for (size_t i = 1; i <= s.size(); i++) {
            if (s[i-1] == '(') {
                cnt++;
            } else {
                if (cnt > 0) {  
                    cnt--;
                    dp[i] = 2;
                    if (s[i-2] == ')')  
                        dp[i] += dp[i-1];                        
                    dp[i] += dp[i-dp[i]];
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
    
};



