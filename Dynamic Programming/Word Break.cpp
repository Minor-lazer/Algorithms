/*
*
*Problem Link : https://leetcode.com/problems/word-break/
*Platform: leetcode
*Status: correct
*Author: Mayukh Chakrabarti (https://github.com/MayukhC99)
*
*/

#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);
#define booster cout.tie(NULL)
#define endl "\n"

typedef long long int lld;

#define mp make_pair
#define pb push_back
#define fi first
#define si second
#define pii pair<lld,lld>
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;

#define mod 1000000007
const lld inf= 1e12;

using namespace std;


class Solution {
    unordered_map<string,int> mp;
    
    void solve(string& s, int& n , vector<bool>& dp , int start, int end){
        if(n+1 == end)
            return;
        
        if(start>end)
            solve(s,n,dp,0,end+1);
        else{
            if( mp.find( s.substr( start , end - start ) ) != mp.end() )
                dp[end] = max(dp[end] , dp[start]);
                
            solve(s,n,dp,start+1,end);
        }
        
        return ;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i=0; i<wordDict.size(); i++)
            mp[wordDict[i]]++; //adding words in map for faster searches
        
        int n = s.length();
        vector<bool> dp(n+2,false);
        dp[0] = true; //dp indexing will start from 1. 0 for empty string
        
        solve(s , n , dp , 0 , 1);
        return dp[n];
    }
};


int main(){
	Solution s;
	vector<string> word = {"cats","dog","sand","and","cat"};
	string str = "catsandog";
	if(s.wordBreak(str,word))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	return 0;
}



