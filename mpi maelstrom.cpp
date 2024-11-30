#include <bits/stdc++.h>
using namespace std;
#define For(i, a, b) for (int i = a; i <= b; i++)
#define INF 500000000
#define maxN 101

int main() {
    int n, a[maxN][maxN], val;
    string s;
    while (cin >> n) {
        For(i, 1, n)
            For(j, 1, n)
                a[i][j] = (i == j) ? 0 : INF;

        For(i, 2, n)
            For(j, 1, i - 1) {
                cin >> s;
                if (s == "x") a[i][j] = a[j][i] = INF;
                else {
                    val = stoi(s);
                    a[i][j] = a[j][i] = val;
                }
            }
        For(k, 1, n)
            For(u, 1, n)
                For(v, 1, n)
                    a[u][v] = min(a[u][v], a[u][k] + a[k][v]);

        int ans = 0;
        For(i, 1, n) ans = max(ans, a[1][i]);
        cout << ans << endl;
    }
}

