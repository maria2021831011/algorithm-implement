#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> dp, parent;
vector<bool> visited;
vector<int> topo_order;

void dfs(int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
    topo_order.push_back(node);
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    dp.resize(n + 1, INT_MIN);
    parent.resize(n + 1, -1);
    visited.resize(n + 1, false);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    reverse(topo_order.begin(), topo_order.end());

    dp[1] = 1;

    for (int node : topo_order) {
        if (dp[node] != INT_MIN) {
            for (int neighbor : adj[node]) {
                if (dp[node] + 1 > dp[neighbor]) {
                    dp[neighbor] = dp[node] + 1;
                    parent[neighbor] = node;
                }
            }
        }
    }

    if (dp[n] == INT_MIN) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    vector<int> path;
    int current = n;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());

    cout << path.size() << endl;
    for (int city : path) {
        cout << city << " ";
    }
    cout << endl;

    return 0;
}
