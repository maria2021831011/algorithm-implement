
#include <bits/stdc++.h>
using namespace std;

void printPath(map<string, string> &prev, string v) {
    string u = prev[v];
    if (u != v)
        printPath(prev, u);
    cout << v[0];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        map<string, vector<string>> adjList;
        for (int i = 0; i < m; ++i) {
            string u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        for (int i = 0; i < n; ++i) {
            string s, k;
            cin >> s >> k;
            queue<string> q;
            map<string, string> prev;

            prev[s] = s;
            q.push(s);
            while (!q.empty() && !prev.count(k)) {
                string u = q.front();
                q.pop();
                for (size_t j = 0; j < adjList[u].size(); ++j) {
                    string v = adjList[u][j];
                    if (!prev.count(v)) {
                        prev[v] = u;
                        q.push(v);
                    }
                }
            }
            printPath(prev, k);
            cout << endl;
        }
        if (t)
            cout << endl;
    }
    return 0;
}
