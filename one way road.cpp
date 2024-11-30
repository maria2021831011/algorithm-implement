#include <bits/stdc++.h>

using namespace std;

void solve(int tc) {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> adj(n + 1);
    map<pair<int, int>, int> mp;
    for (int i = 1; i <= n; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        mp[{u, v}] = cost;
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});
    }

    int ans1 = 0;
    int cur_city = 1, next_city = adj[1][0].first, temp;

    for (int i = 1; i <= n; i++) {
        if (mp[{cur_city, next_city}] == 0)
            ans1 += mp[{next_city, cur_city}];

        temp = adj[next_city][0].first;
        if (temp == cur_city)
            temp = adj[next_city][1].first;

        cur_city = next_city;
        next_city = temp;
    }

    int ans2 = 0;
    cur_city = 1;
    next_city = adj[1][1].first;

    for (int i = 1; i <= n; i++) {
        if (mp[{cur_city, next_city}] == 0)
            ans2 += mp[{next_city, cur_city}];

        temp = adj[next_city][0].first;
        if (temp == cur_city)
            temp = adj[next_city][1].first;

        cur_city = next_city;
        next_city = temp;
    }

    cout << "Case " << tc << ": " << min(ans1, ans2) << "\n";
}

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        solve(tc);

    return 0;
}
