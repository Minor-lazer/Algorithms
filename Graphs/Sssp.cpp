#include<bits/stdc++.h>
using namespace std;

int vis[100001];
int sssp[100001];
vector<int> vc[100001];

void dfs(int v,int ct)
{
    vis[v]=1;
    sssp[v]=ct;
    for(int i=0;i<vc[v].size();i++)
    {
        if(vis[vc[v][i]]==0)
        {
            dfs(vc[v][i],ct+1);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    memset(vis,0,sizeof(vis));
    memset(sssp,0,sizeof(sssp));
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        vc[x].push_back(y);
        vc[y].push_back(x);
    }
    dfs(1,sssp[1]);
    for(int i=1;i<=n;i++)
    {
        cout<<sssp[i]<<" ";
    }
}