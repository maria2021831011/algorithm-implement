#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> edge;

int t, n, c, nc, d, c1, c2;
vector<int> camarade[100005];

int bfs() {
    vector<int> path(n, -1);
    queue<int> q;
    path[c1] = 0;
    q.push(c1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        int w = path[u] + 1;

        for (int v : camarade[u]) {
            if (path[v] == -1 || w < path[v]) {
                if (v == c2) return w - 1;
                q.push(v);
                path[v] = w;
            }
        }
    }
    return -1;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            camarade[i].clear();
            cin >> c >> nc;
            for (int j = 0; j < nc; ++j) {
                cin >> d;
                camarade[i].push_back(d);
            }
        }
        cin >> c1 >> c2;
        cout << c1 << " " << c2 << " " << bfs() << "\n";
        if (t) cout << "\n";
    }
    return 0;
}
