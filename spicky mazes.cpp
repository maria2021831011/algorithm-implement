#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

bool bfs(vector<vector<char>>& s, int a, int b, int z, vector<vector<bool>>& vis) {
    int n = s.size();
    int m = s[0].size();

    if (a < 0 || a >= n || b < 0 || b >= m || z < 0 || s[a][b] == '#') return false;
    if (s[a][b] == 'x') return true;

    if (!vis[a][b]) {
        vis[a][b] = true;

        for (int i = 0; i < 4; i++) {
            int nx = a + dx[i];
            int ny = b + dy[i];

            if (bfs(s, nx, ny, (s[a][b] == 's') ? z - 1 : z, vis)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m, x, a, b;
    cin >> n >> m >> x;

    vector<vector<char>> s(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> s[i][j];
            if (s[i][j] == '@') {
                a = i;
                b = j;
            }
        }
    }

    if (bfs(s, a, b, x/2, vis)) {
        cout << "SUCCESS" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}

