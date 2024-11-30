
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
bool vis[10001];
int dis[10001];
int n, m;

void dijkstra(int s, vector<pair<int, int>> adj[]) {
    for (int i = 0; i < 10001; i++) {
        vis[i] = false;
        dis[i] = INF;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {


        int u = pq.top().second;
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (auto pp : adj[u]) {
            int v = pp.second;
            int w = pp.first;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<pair<int, int>> adj[10001];
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({w, v});
        }
        int a, b;
        cin >> a >> b;
        dijkstra(a, adj);
        if (dis[b] < INF)
            cout << dis[b] << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

