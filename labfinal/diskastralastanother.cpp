
#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 5;
vector<vector<pair<int, int>>> v(mx); // Sized vector
vector<int> dist(mx, INT_MAX), par(mx, -1);
vector<bool> vis(mx, false);
int N, E;

bool dijkstra(int st, int en) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[st] = 0;
    pq.push({0, st});

    while (!pq.empty()) {
        int h = pq.top().second;
        pq.pop();
        if (h == en) {
            return true;
        }
        if (vis[h]) continue;
        vis[h] = true;

        for (auto [t, w] : v[h]) {
            if (!vis[t] && dist[h] + w < dist[t]) {
                dist[t] = dist[h] + w;
                pq.push({dist[t], t});  // Corrected this part
                par[t] = h;
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
        int u, k, w;
        cin >> u >> k >> w;
        v[u].push_back({k, w});
        v[k].push_back({u, w});
    }

    if (dijkstra(1, N)) {
        vector<int> path;
        for (int i = N; i != -1; i = par[i]) {
            path.push_back(i);
        }
        reverse(path.begin(), path.end());

        for (auto node : path) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << -1 << "\n";
    }

    return 0;
}
