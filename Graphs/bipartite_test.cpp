#include<bits/stdc++.h>
using namespace std;

int vis[10001];
int col[10001];
vector<int> vc[10001];

bool bipartite_test(int v,int cl)
{
    vis[v]=1;
    col[v]=cl;
    for(int i=0;i<vc[v].size();i++)
    {
        if(vis[vc[v][i]]==0)
        {
            if(bipartite_test(vc[v][i],cl^1)==false)
            {
                return false;
            }
        }
        else
        {
            if(col[vc[v][i]] == cl)
            {
                return false;
            }   
        }
    }
    return true;
}
int main()
{
    int n,m;
    cin>>n>>m;
    memset(vis,0,sizeof(vis));
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        vc[x].push_back(y);
        vc[y].push_back(x);
    }
    bool ct;
    ct = bipartite_test(1,0);
    if(ct){cout<<"YES";}
    else
    {
        cout<<"NO";
    }
    
}