
#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
bool vis[N][N];
#define pii pair<int,int>
int dx[] = {0, 0, -1, +1};
int dy[] = {+1, -1, 0, 0};
int dist[N][N];

bool isValid(int nx, int ny, int r, int c) {
    return (nx >= 0 && nx < r && ny >= 0 && ny < c && vis[nx][ny] != 1);
}

void bfs(int x, int y, int r, int c) {
    queue<pii> q;
    q.push({x, y});
    vis[x][y] = 1;

    while (!q.empty()) {
        pii u = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = u.first + dx[k];
            int ny = u.second + dy[k];

            if (isValid(nx, ny, r, c)) {
                q.push({nx, ny});
                vis[nx][ny] = 1;
                dist[nx][ny] = dist[u.first][u.second] + 1;
            }
        }
    }
}

int main() {
    int r, c;
    while (cin >> r >> c) {
        if (r == 0 && c == 0) break;
        memset(vis, 0, sizeof(vis));
        memset(dist, 0, sizeof(dist));
        int row;
        cin >> row;
        for (int i = 0; i < row; i++) {
            int n, c;
            cin >> n >> c;
            int a;
            for (int j = 0; j < c; j++) {
                cin >> a;
                vis[n][a] = 1;
            }
        }
        int s1, e1, s2, e2;
        cin >> s1 >> e1 >> s2 >> e2;
        bfs(s1, e1, r, c);
        cout << dist[s2][e2] << endl;
    }
    return 0;
}
