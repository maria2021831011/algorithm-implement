#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    int T, M, N, P, size;
    string id1, id2;

    cin >> T;
    cout << "SHIPPING ROUTES OUTPUT" << endl;

    for (int t = 1; t <= T; t++) {
        cout << "\nDATA SET  " << t << "\n" << endl;

        cin >> M >> N >> P;
        map<string, int> index;
        vector<vector<pair<int, int>>> adj(M);

        for (int i = 0; i < M; i++) {
            cin >> id1;
            index[id1] = i;
        }

        for (int i = 0; i < N; i++) {
            cin >> id1 >> id2;
            int u = index[id1], v = index[id2];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 1});
        }

        for (int i = 0; i < P; i++) {
            cin >> size >> id1 >> id2;
            int start = index[id1], end = index[id2];

            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            vector<int> dist(M, INF);
            dist[start] = 0;
            pq.push({0, start});

            while (!pq.empty()) {
                int d = pq.top().first;
                int node = pq.top().second;
                pq.pop();

                if (d > dist[node]) continue;

                for (auto neighbor : adj[node]) {
                    int nextNode = neighbor.first, weight = neighbor.second;
                    if (dist[node] + weight < dist[nextNode]) {
                        dist[nextNode] = dist[node] + weight;
                        pq.push({dist[nextNode], nextNode});
                    }
                }
            }

            if (dist[end] == INF)
                cout << "NO SHIPMENT POSSIBLE" << endl;
            else
                cout << "$" << size * dist[end] * 100 << endl;
        }
    }

    cout << "\nEND OF OUTPUT" << endl;
    return 0;
}
