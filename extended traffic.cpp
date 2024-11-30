#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
int main() {
    int t;
    cin >> t;
    for (int cm = 1; cm <= t; cm++) {
        int n, m;
        cin >> n;
        vector<int> busyness(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> busyness[i];
        }
        cin >> m;
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            int fee = pow(busyness[v] - busyness[u], 3);
            adj[u].push_back({v, fee});
        }
        vector<int> dist(n + 1, INF);
        dist[1] = 0;

        for (int i = 1; i <= n - 1; i++) {
            for (int u = 1; u <= n; u++) {
                for (auto edge : adj[u]) {
                    int v = edge.first;
                    int weight = edge.second;
                    if (dist[u] != INF && dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }

        int q;
        cin >> q;
        cout << "Case " << cm << ":" << endl;
        while (q--) {
            int dest;
            cin >> dest;
            if (dist[dest] < 3 || dist[dest] == INF) {
                cout << "?" << endl;
            } else {
                cout << dist[dest] << endl;
            }
        }
    }
    return 0;
}
