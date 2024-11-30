#include<bits/stdc++.h>
using namespace std;
int vis[101][2];
vector<vector<int>>adjlist;
void dfs(int current,int p)
{
    if(p!=-1)
    vis[current][p]=1;
    //
    p++;
    p=p%2;
    for(auto u:adjlist[current])
    {
        if(!vis[u][p])
        {
            dfs(u,p);

        }
    }

}
int main()
{
    int t, k=0;
    cin>>t;
    while(t--)
    {k++;
        int n,m;
        cin>>n>>m;
        adjlist.assign(n + 1, vector<int>());
        memset(vis, 0, sizeof(vis));
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;;
            adjlist[x].push_back(y);
            adjlist[y].push_back(x);
        }
        dfs(1,-1);
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(vis[i][1]==1)
            {
                 ans++;
            }
        }
        cout<<"Case "<<k<<": "<<ans<<endl;
    }
    return 0;

}
