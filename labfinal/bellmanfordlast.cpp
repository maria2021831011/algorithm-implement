
#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>>adj;
void bellmanford(int s, int n) {
    vector<int> dis(n, 1e9);
    dis[s] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (auto it : adj[u]) {
                int v = it.first;
                int weight = it.second;
                if (dis[u] != 1e9 && dis[u] + weight < dis[v]) {
                    dis[v] = dis[u] + weight;
                }
            }
        }
    }

    for (int u = 0; u < n; u++) {
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (dis[u] + weight < dis[v]) {
                cout << "Negative cycle found\n";
                return;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "Distance from source to vertex " << i << " is: " << dis[i] << endl;
    }
}

int main() {
    int n, m;
    adj.resize(n+1);
    cin >> n >> m;
for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    bellmanford(0,  n);
    return 0;
}
