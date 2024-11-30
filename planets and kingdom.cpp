
#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200001;
vector<int> g[MAX_N];
vector<int> tg[MAX_N];
bool vis[MAX_N];
stack<int> st;
int r[MAX_N];

void dfs(int n) {
    if (vis[n]) return;

    vis[n] = true;

    for (int v : g[n]) {
        dfs(v);
    }
    st.push(n);
}

void dfs_print(int n, int c) {
    if (vis[n]) return;

    vis[n] = true;
    r[n] = c;

    for (int v : tg[n]) {
        dfs_print(v, c);
    }
}

void kosarajus(int n) {
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
    }

    int c = 0;
    while (!st.empty()) {
        int u = st.top();
        st.pop();

        if (!vis[u]) {
            dfs_print(u, ++c);
        }
    }
    cout << c << endl;
    for (int i = 1; i <= n; i++) {
        cout << r[i] << " ";
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        vis[i] = false;
        g[i].clear();
        tg[i].clear();
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        tg[v].push_back(u);
    }
    kosarajus(n);

    return 0;
}
