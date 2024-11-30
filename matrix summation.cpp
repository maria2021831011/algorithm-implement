
#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL tree[1050][1050];

void update(int x, int y, int val, int MAX) {
    while (x <= MAX) {
        int ty = y;
        while (ty <= MAX) {
            tree[x][ty] += val;
            ty += (ty & -ty);
        }
        x += (x & -x);
    }
}

LL read(int x, int y) {
    LL sum = 0;
    while (x) {
        int ty = y;
        while (ty) {
            sum += tree[x][ty];
            ty -= (ty & -ty);
        }
        x -= (x & -x);
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        memset(tree, 0, sizeof tree);

        while (true) {
            char s[10];
            cin >> s;

            if (s[1] == 'E') {
                int x, y, val;
                cin >> x >> y >> val;
                LL p = read(x + 1, y + 1) + read(x, y) - read(x + 1, y) - read(x, y + 1);
                update(x + 1, y + 1, val - p, n);
            } else if (s[1] == 'U') {
                LL sum = 0;
                int x1, y1, x, y;
                cin >> x >> y >> x1 >> y1;
                sum = read(x1 + 1, y1 + 1) + read(x, y) - read(x, y1 + 1) - read(x1 + 1, y);
                cout << sum << '\n';
            } else {
                break;
            }
        }
        cout << '\n';
    }
    return 0;
}
