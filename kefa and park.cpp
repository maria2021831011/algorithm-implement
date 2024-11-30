#include <bits/stdc++.h>
using namespace std;
const int Size = 100005;
#define ll long long
vector<ll> adj[Size];
bool vis[Size];
ll n, m, total = 0;
ll cc[Size];
void dfs(ll s, ll sum) {
    if (vis[s]) return;
    vis[s] = true;
    if (cc[s]) sum++;
    else sum = 0;

    if (sum > m) return;

    if (s != 1 && adj[s].size() == 1) {
        total++;
    }

    for (ll neighbor : adj[s]) {
        dfs(neighbor, sum);
    }
}

int main() {
    memset(vis, false, sizeof(vis));
    cin >> n >> m;
    for (ll i = 1; i <= n; ++i) {
        cin >> cc[i];
    }
    for (ll i = 0; i < n - 1; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << total << endl;

    return 0;
}
