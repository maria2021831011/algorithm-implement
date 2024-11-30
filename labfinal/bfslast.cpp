/*#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<int>vis;
void bfs(int s){
queue<int>q;
vis[s]=true;
q.push(s);
while(!q.empty( ))
{
    int j=q.front();
    cout<<j<<" ";
    q.pop();
    for(auto k:adj[j]){

        if(!vis[k])
        {
            vis[k]=true;
            q.push(k);
        }
    }
}
}

int main(){
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    vis.assign(n+1,false);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
}*/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis;

// BFS function
void bfs(int s) {
    queue<int> q;
    vis[s] = true;
    q.push(s);

    while (!q.empty()) {
        int j = q.front();
        cout << j << " ";
        q.pop();

        for (auto k : adj[j]) {
            if (!vis[k]) {
                vis[k] = true;
                q.push(k);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    vis.assign(n + 1, false);

    // Read edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Handle disconnected components
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            bfs(i);
        }
    }

    return 0;
}

