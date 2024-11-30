#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> in_degree;
vector<int> order;
queue<int> q;

void topological_sort(int n) {
    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0)
                q.push(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    in_degree.assign(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        in_degree[b]++;
    }

    topological_sort(n);

    if (order.size() != n) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int node : order) {
            cout << node << " ";
        }
        cout << "\n";
    }

    return 0;
}
