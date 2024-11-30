
#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n, p;
        cin >> n >> p;
        vector<pair<int, int>> k;

        vector<int> a(n);
        vector<int>b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {

            cin >> b[i];
            k.push_back({min(p, b[i]), a[i]});
        }


        sort(k.begin(), k.end());

        int ans = p;
        int pe = n - 1;

        for (int i = 0; i < n - 1; i++) {
            ans += min(k[i].second, pe) * k[i].first;
            pe -= min(pe, k[i].second);
        }

        cout << ans << endl;
    }

    return 0;
}

