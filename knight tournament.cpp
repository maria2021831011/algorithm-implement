
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<int> s;
    for (int i = 1; i <= n; i++) s.insert(i);
    vector<int> result(n + 1, 0);

    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;
        auto it = s.lower_bound(l);
        while (it != s.end() && *it <= r) {
            if (*it != x) {
                result[*it] = x;
                it = s.erase(it);
            } else {
                it++;
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << result[i] << " ";
    cout << endl;
    return 0;
}
