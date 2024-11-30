#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 52;
char grid[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];
int n, m;
const int dirx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int diry[] = {-1, 1, 0, 0, 1, 1, -1, -1};
int lon(int x, int y) {
    if (dp[x][y] != -1)
        return dp[x][y];

    int maxl= 1;
    for (int i = 0; i < 8; ++i) {
        int xx = x + dirx[i];
        int yy = y + diry[i];

        if (xx >= 0 && xx < n && yy >= 0 && yy < m && grid[xx][yy] == grid[x][y] + 1) {
            maxl= max(maxl, 1 + lon(xx, yy));
        }
    }

    return dp[x][y] = maxl;
}

int main() {
    int t= 1;
    while (cin >> n >> m) {
        if (n == 0 && m == 0)
            break;

        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }

        memset(dp, -1, sizeof(dp));

        int ma= 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'A') {
                    ma = max(ma, lon(i, j));
                }
            }
        }

        cout << "Case " << t++ << ": " << ma<< endl;
    }
    return 0;
}

