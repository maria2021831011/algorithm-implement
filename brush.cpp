#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int n, m;
vector<int> dis;
vector<vector<pair<int, int>>> adj;
void dijkstra(int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    dis[source] = 0;
    q.push({0, source});
    while (!q.empty()) {
        int u = q.top().second;
        int w = q.top().first;
        q.pop();
        if (w > dis[u]) continue;
        for (auto next : adj[u]) {
            int v = next.second;
            int weight = next.first;
            if (dis[u] + weight < dis[v]) {
                dis[v] = dis[u] + weight;
                q.push({dis[v], v});
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    for (int caseno = 1; caseno <= t; caseno++) {
        cin >> n >> m;
        adj.assign(n + 1, vector<pair<int, int>>());
        dis.assign(n + 1, INF);

        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }
        dijkstra(1);
        cout << "Case " << caseno << ": ";
        if (dis[n] == INF) {
            cout << "Impossible" << endl;
        } else {
            cout << dis[n] << endl;
        }
    }

    return 0;
}
