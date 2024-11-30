#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<vector<pair<ll, ll>>> adj;
vector<ll> dif, vis;
ll mx, mxnode;
void dfs(ll s, ll d) {
    vis[s] = 1;
    dif[s] = d;
    if (d > mx) {
        mx = d;
        mxnode = s;
    }
    for (auto edge : adj[s]) {
        if (!vis[edge.first]) {
            dfs(edge.first, d + edge.second);
        }
    }
}

int main() {
    ll tc;
    cin >> tc;
    for (ll k = 1; k <= tc; k++) {
        ll n;
        cin >> n;

        adj.assign(n,vector<pair<ll,ll>>());
        dif.assign(n, 0);
        vis.assign(n, 0);

        for (ll i = 0; i < n - 1; i++) {
            ll a, b, w;
            cin >> a >> b >> w;
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }
        mx = 0;
        dfs(0, 0);
        ll P = mxnode;
        fill(vis.begin(), vis.end(), 0);
        fill(dif.begin(), dif.end(), 0);
        mx = 0;
        dfs(P, 0);
        vector<ll> P_diff = dif;
        fill(vis.begin(), vis.end(), 0);
        fill(dif.begin(), dif.end(), 0);
        mx = 0;
        ll Q = mxnode;
        dfs(Q, 0);
        vector<ll> Q_diff = dif;
        cout << "Case " << k << ":" << endl;
        for (ll i = 0; i < n; i++) {
            cout << max(P_diff[i], Q_diff[i]) << endl;
        }
    }
    return 0;
}
