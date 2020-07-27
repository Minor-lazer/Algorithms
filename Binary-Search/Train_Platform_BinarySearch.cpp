#include<bits/stdc++.h>
using namespace std;

int platForm(int arr[],int dep[],int n)
{
    int res=1;
    
    int plat=1;
    
    int i=1;
    int j=0;
    
    sort(arr,arr+n);
    
    sort(dep,dep+n);
    
    while(i<n && j<n)
    {
        if(arr[i]<=dep[j])
        {
            plat++;
            i++;
        }
        
        else if(arr[i]>dep[j])
        {
            plat--;
            j++;
        }
        
        if(plat>res)
        {
            res=plat;
        }
    }
    return res;
}

int main()
{
    int t;
    int arr[10000];
        
    int dep[10000];
    
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        
         for(int i=0;i<n;i++)
        {
            cin>>dep[i];
        }
        
        cout<<platForm(arr,dep,n)<<endl;
    }
    
    return 0;
}