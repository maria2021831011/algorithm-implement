
#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<vector<int>> adjList;
int city[N];
int vis[N];
int countReach[N];

void explore(int node, int increment) {
    countReach[node] += increment;
    for (int neighbor : adjList[node]) {
        if (!vis[neighbor]) {
            vis[neighbor] = 1;
            explore(neighbor, increment);
        }
    }
}

int main() {
    int t;
    cin >> t;

    for (int cs = 1; cs <= t; cs++) {
        int k, n, m;
        cin >> k >> n >> m;

        adjList.assign(n + 1, vector<int>());
        memset(city, 0, sizeof(city));
        memset(countReach, 0, sizeof(countReach));

        for (int i = 0; i < k; i++) {
            int startCity;
            cin >> startCity;
            city[startCity]++;
        }

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            adjList[x].push_back(y);
        }

        for (int i = 1; i <= n; i++) {
            if (city[i]) {
                memset(vis, 0, sizeof(vis));
                vis[i] = 1;
                explore(i, city[i]);
            }
        }

        int result = 0;
        for (int i = 1; i <= n; i++) {
            if (countReach[i] >= k) {
                result++;
            }
        }

        cout << "Case " << cs << ": " << result << endl;
    }

    return 0;
}
