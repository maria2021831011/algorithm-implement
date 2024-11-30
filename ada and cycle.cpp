
#include<bits/stdc++.h>
using namespace std;
int bfs(int s, const vector<vector<int>>& adj_list) {
    int n = adj_list.size();
    vector<int> visited(n, 0);
    vector<int> level(n, 0);
    visited[s] = 1;
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i : adj_list[node]) {
            if (!visited[i]) {
                visited[i] = 1;
                level[i] = level[node] + 1;
                q.push(i);
            } else if (i == s) {
                return abs(level[node] - level[i]) + 1;
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> adj_list(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int edge;
            cin >> edge;
            if (edge == 1) {
                adj_list[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        int x = bfs(i, adj_list);
        if (x != -1)
            cout << x << endl;
        else
            cout << "NO WAY" << endl;
    }
    return 0;
}
