
#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> e;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        e.clear();
        e.resize(n);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            e[u].push_back({w, v});
        }
        vector<int> d(n, 1e9);
        d[0] = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int u = 0; u < n; u++) {
                for (auto it : e[u]) {
                    int w = it.first;
                    int v = it.second;
                    if (d[u] != 1e9 && d[u] + w < d[v]) {
                        d[v] = d[u] + w;
                    }
                }
            }
        }

        bool has= false;
        for (int u = 0; u < n; u++) {
            for (auto it : e[u]) {
                int w = it.first;
                int v = it.second;
                if (d[u] != 1e9 && d[u] + w < d[v]) {
                    has= true;
                    break;
                }
            }
            if (has) break;
        }
        if (has)
            cout << "possible" << endl;
        else
            cout << "not possible" << endl;
    }

    return 0;
}
