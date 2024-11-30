
#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
const int mx = 1e5 + 5;
vector<pii> adj[mx];
vector<int> dist(mx, INT_MAX), par(mx, -1);
vector<bool> vis(mx, false);
int N, E;

bool dijkstra(int st, int en) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[st] = 0;
    pq.emplace(0, st);

    while (!pq.empty()) {
        int h = pq.top().second;
        pq.pop();

        if (h == en) {
            return true;
        }

        if (vis[h]) continue;
        vis[h] = true;

        for (const auto& [v, w] : adj[h]) {
            if (!vis[v] && dist[h] + w < dist[v]) {
                dist[v] = dist[h] + w;
                pq.emplace(dist[v], v);
                par[v] = h;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> E;
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    if (dijkstra(1, N)) {
        vector<int> path;
        for (int i = N; i != -1; i = par[i]) {
            path.push_back(i);
        }
        reverse(path.begin(), path.end());
        for (int node : path) {
            cout << node << " ";
        }
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}
