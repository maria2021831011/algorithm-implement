

#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
void shortest_path(vector<vector<int>>& maze, vector<vector<int>>& dist) {
    int n = maze.size();
    int m = maze[0].size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
pq.push({maze[0][0], {0, 0}});
    dist[0][0] = maze[0][0];

    while (!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[x][y])
            continue;

        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (dist[x][y] + maze[nx][ny] < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + maze[nx][ny];
                    pq.push({dist[nx][ny], {nx, ny}});
                }
            }
        }
    }
}

int main() {
    int t;
    cin >> t;while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> maze(n, vector<int>(m));
        vector<vector<int>> dist(n, vector<int>(m, INF));
 for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> maze[i][j];
            }
        }
shortest_path(maze, dist);
cout << dist[n - 1][m - 1] << endl;
    }
return 0;}
