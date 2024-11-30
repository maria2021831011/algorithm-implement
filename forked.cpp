#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b, xk, yk, xq, yq;
        cin >> a >> b >> xk >> yk >> xq >> yq;
        vector<int> dx = {-a, -a, a, a, b, b, -b, -b};
        vector<int> dy = {-b, b, b, -b, a, -a, a, -a};
        set<pair<int, int>> k;
        set<pair<int, int>> q;

        for(int i = 0; i < 8; i++) {
            k.insert({xk + dx[i], yk + dy[i]});
        }

        for(int i = 0; i < 8; i++) {
            q.insert({xq + dx[i], yq + dy[i]});
        }

        int ans = 0;
        for(auto i : k) {
            if(q.find(i) != q.end()) {
                ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
