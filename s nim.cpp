
#include <bits/stdc++.h>

using namespace std;

int grundy[10003];
int n;
int a[105];

int mex(set<int>& h) {
    int mex = 0;
    while (h.find(mex) != h.end())
        mex++;
    return mex;
}

int calculate(int d) {
    if (d < a[0]) {
        return 0;
    }
    if (grundy[d] != -1) {
        return grundy[d];
    }
    set<int> s;
    for (int i = 0; i < n; i++) {
        if (d >= a[i]) {
            s.insert(calculate(d - a[i]));
        }
    }
    grundy[d] = mex(s);
    return grundy[d];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);

    int m;
    cin >> m;
    memset(grundy, -1, sizeof(grundy));
    while (m--) {
        int p, k, ans = 0;
        cin >> p;
        for (int i = 0; i < p; i++) {
            cin >> k;
            ans ^= calculate(k);
        }
        if (ans == 0) {
            cout << "L" ;
        } else {
            cout << "W" ;
        }
    }
    return 0;
}
