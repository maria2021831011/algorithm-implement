#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> dis;
int n;

void dijkstra(int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis.assign(n, 1e9);
    dis[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int current_max = pq.top().first;
        pq.pop();

        if (current_max > dis[u]) continue;

        for (auto it : adj[u]) {
            int v = it.second;
            int w = it.first;
            int temp = max(current_max, w);

            if (temp < dis[v]) {
                dis[v] = temp;
                pq.push({dis[v], v});
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int case_num = 1; case_num <= t; case_num++) {
        int e;
        cin >> n >> e;

        adj.assign(n, vector<pair<int, int>>());

        for (int i = 0; i < e; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({w, v});
            adj[v].push_back({w, u});
        }

        int m;
        cin >> m;
        dijkstra(m);

        cout << "Case " << case_num << ":\n";
        for (int i = 0; i < n; i++) {
            if (dis[i] == 1e9)
                cout << "Impossible\n";
            else
                cout << dis[i] << "\n";
        }
    }

    return 0;
}

