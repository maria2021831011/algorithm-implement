#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int parent[1000001], rankSet[1000001];
int find(int x) {
    return (parent[x] == x) ? x : (parent[x] = find(parent[x]));
}

bool unite(int x, int y) {
    int rootX = find(x), rootY = find(y);
    if (rootX == rootY) return false;
    if (rankSet[rootX] < rankSet[rootY]) swap(rootX, rootY);
    parent[rootY] = rootX;
    if (rankSet[rootX] == rankSet[rootY]) rankSet[rootX]++;
    return true;
}

int kruskal(vector<vector<int>>& edges, int n) {
    sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) { return a[2] < b[2]; });
    for (int i = 1; i <= n; i++) parent[i] = i, rankSet[i] = 0;
    int cost = 0, cnt = 0;
    for (auto& e : edges) {
        if (unite(e[0], e[1])) {
            cost += e[2];
            if (++cnt == n - 1) break;
        }
    }
    return cost;
}

int main() {
    int n, k, m;
    bool first = true;
    while (cin >> n) {
        vector<vector<int>> edges;
        int u, v, w, originalCost = 0;

        for (int i = 0; i < n - 1; i++) {
            cin >> u >> v >> w;
            originalCost += w;
        }

        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }

        if (!first) cout << "\n";
        first = false;

        cout << originalCost << "\n" << kruskal(edges, n) << "\n";
    }
    return 0;
}

