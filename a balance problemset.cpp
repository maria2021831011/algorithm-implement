#include <bits/stdc++.h>
using namespace std;



int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, n, p = -1;
        cin >> x >> n;
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                if (x / i >= n) {
                    p = max(p, i);
                }
                if (i >= n) {
                    p = max(p, x / i);
                }
            }
        }

        cout << p << endl;
    }

    return 0;
}
