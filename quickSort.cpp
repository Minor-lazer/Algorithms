#include<bits/stdc++.h>
using namespace std;
#define ot(x) cout<<x<<" ";
#define out(x) cout<<x<<"\n";
#define pb push_back
#define in insert
#define ll long long int
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define yes cout<<"yes\n";
#define no cout<<"no\n";
#define Yes cout<<"Yes\n";
#define No cout<<"No\n";
#define f(i,x,a) for(i=x;i<a;i++)
#define next cout<<"\n";
#define sp(n) cout<<fixed<<setprecision(n);
#define  gcd(a,b)    __gcd(a,b)
#define bs  binary_search
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define test int t;cin>>t;while(t-->0)
#define mod 1000000007

int part(int a[],int l,int h){
  int pt=a[l],i=l-1,j=h+1;
  while(true){
      do{
          i++;
      }while(a[i]<pt);
      do{
          j--;
      }while(a[j]>pt);
      if(i>=j){
          return j;
      }
      swap(a[i],a[j]);
  }
}

void xyz(int a[],int l,int h){
if(l<h){
    int p=part(a,l,h);
    xyz(a,l,p);
    xyz(a,p+1,h);
}
}

void pa(int a[],int n){
    int i;
    f(i,0,n){
        cout<<a[i]<<" ";
    }
}

int main()
{
 fast
 int n,i;cin>>n;
 int a[n];
 f(i,0,n){
     cin>>a[i];
 }
 xyz(a,0,n-1);
 pa(a,n);
  return 0;
}

