#include <bits/stdc++.h>
#define inf 1000000000
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> vis, dis;

void bfs(int start) {
    fill(vis.begin(), vis.end(), 0);
    fill(dis.begin(), dis.end(), inf);

    queue<int> q;
    vis[start] = 1;
    dis[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (!vis[v]) {
                vis[v] = 1;
                dis[v] = dis[u] + weight;
                q.push(v);
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int test_case = 1; test_case <= t; test_case++) {
        int n;
        cin >> n;
        adj.assign(n, vector<pair<int, int>>());
        vis.assign(n, 0);
        dis.assign(n, 0);
        for (int i = 0; i < n - 1; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        bfs(0);
        int max_distance_node = max_element(dis.begin(), dis.end()) - dis.begin();
        bfs(max_distance_node);
        int final_max_distance = *max_element(dis.begin(), dis.end());

        cout << "Case " << test_case << ": " << final_max_distance << endl;
    }
    return 0;
}

