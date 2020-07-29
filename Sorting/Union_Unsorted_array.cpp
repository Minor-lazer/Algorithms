#include<bits/stdc++.h>
using namespace std;

vector<int> sortUnion(int arr[],int brr[],int n,int m)
{
    unordered_set<int>inset;
    unordered_set<int>duplicate;
    vector<int>v;
    
    for(int i=0;i<n;i++)
    {
        if(inset.find(arr[i])==inset.end())
        {
            inset.insert(arr[i]);
            v.push_back(arr[i]);
            
        }
        
     
    }
    
    
    for(int i=0;i<m;i++)
    {
        if(inset.find(brr[i])==inset.end())
        {
            inset.insert(brr[i]);
            v.push_back(brr[i]);
            
        }
        
       
    }
    
    sort(v.begin(),v.end());
    
    return v;
    
    
}

int main()
{
    int t;
    
    cin>>t;
    
    while(t--)
    {
        int n,m;
        
        cin>>n;
        
        cin>>m;
        
        int arr[10000];
        
        int brr[10000];
        
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        
        for(int i=0;i<m;i++)
        {
            cin>>brr[i];
        }
        
       vector<int> ans= sortUnion(arr,brr,n,m);
        
        for(int x:ans)
        {
            cout<<x<<" ";
        }
        
        
    }
    return 0;
}

