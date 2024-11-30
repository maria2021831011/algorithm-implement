#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e5 + 5;
int n, m, k;
priority_queue<ll> s[INF];
vector<pair<int, int>> adj[INF];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    s[1].push(0);
    pq.push({0, 1});
    while (!pq.empty()) {
        int u = pq.top().second;
        ll w = pq.top().first;
        pq.pop();
        if (w > s[u].top()) continue;
        for (auto &i : adj[u]) {
            int v = i.first;
            ll tmp = w + i.second;
            if (s[v].size() < k) {
                s[v].push(tmp);
                pq.push({tmp, v});
            } else if (tmp < s[v].top()) {
                s[v].pop();
                s[v].push(tmp);
                pq.push({tmp, v});
            }
        }
    }
    vector<ll> ans;
    while (!s[n].empty()) {
        ans.push_back(s[n].top());
        s[n].pop();
    }
    reverse(ans.begin(), ans.end());
    for (auto a : ans) cout << a << " ";
}
