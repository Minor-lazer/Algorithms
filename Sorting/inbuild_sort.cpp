#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a,int b){
	cout<<"compare"<<a<<"and"<<b<<endl;
	return a>b;
}


int main(){
	int a[1000],n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	
	for(int i=0;i<n;i++){
		cout<<a[i]<<endl;
	}
	return 0;
}
