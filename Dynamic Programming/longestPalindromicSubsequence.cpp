#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n)  for(int i=a;i<n;i++)
const int Nmax = (int) 1e5+5 ;
string s;
vector<char>ans;
// this fn will return the length of LPS.
int findLPS(int startIndex, int endIndex){
	if(startIndex == endIndex) return 1;
	if(startIndex + 1 == endIndex && s[startIndex]==s[endIndex])
		return 2;
	if(s[startIndex] == s[endIndex])
		return 2+findLPS(startIndex+1, endIndex-1);
	return max(findLPS(startIndex+1,endIndex), findLPS(startIndex,endIndex-1));
}
// this function will return both string and length using LCS:
void usingLongestCommonSubseuence(string p){
	string s1 = p ;
	reverse(p.begin(),p.end());
	string s2 = p;
	int n = p.length();
	int LCS[n+1][n+1]; //LCS[i][j] is LCS of s1[0..i-1] and s2[0...j-1]
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i==0 || j==0) LCS[i][j]=0;
			else if(s[i-1] == s2[j-1])
					LCS[i][j] = 1 + LCS[i-1][j-1];
			else LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
		}
	}
//	for(int i=0;i<=n;i++){
//		for(int j=0;j<=n;j++){
//			cout<<LCS[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<LCS[n][n]<<endl;

	//printing the LCS:
	int ansSize = LCS[n][n];
	string lcs(ansSize, '\0');
	int row = n, col = n;
	while(row>0 && col > 0){
		if(s1[row-1] == s2[col-1]){
			lcs[ansSize-1] = s1[row-1];
			ansSize--,row--,col--;
		}
		else if(LCS[row-1][col] > LCS[row][col-1]){
			row--;
		}else col--;
	}
	cout<<lcs<<endl;
}
int main()
{
	
	cin>>s;
	cout<<"The length of longest palindromic subsequence(direct solution): ";
	cout<<findLPS(0,s.length()-1)<<endl;
	
	cout<<"The length of longest palindromic subsequence(using LCS): "; 
	
	usingLongestCommonSubseuence(s);
}

