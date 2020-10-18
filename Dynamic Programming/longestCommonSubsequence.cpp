#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n)  for(int i=a;i<n;i++)
const int Nmax = (int) 1e5+5 ;

string s1,s2;
string ans="";
int findLengthOfLCS(int lastIndexOfS1, int lastIndexOfS2){ // m = lastIndexOfS1, n = lastIndexOfS2
	
	if(lastIndexOfS1<0 || lastIndexOfS2<0 ) return 0;
	
	if(s1[lastIndexOfS1]==s2[lastIndexOfS2]){
		ans+=s1[lastIndexOfS1];
		return 1+findLengthOfLCS(lastIndexOfS1-1,lastIndexOfS2-1);
	}
	else  return max(findLengthOfLCS(lastIndexOfS1-1,lastIndexOfS2), findLengthOfLCS(lastIndexOfS1,lastIndexOfS2-1));
}

// using DP:

int main()
{
	cin>>s1>>s2;
	
	cout<<"The Longest Common Subsequence length: ";
	cout<<findLengthOfLCS(s1.length()-1, s2.length()-1);
	cout<<" ";
	(reverse(ans.begin(),ans.end()));
	cout<<ans;
	return 0;
}

