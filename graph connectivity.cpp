#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

#define MAX 30

vector<int> grafo[MAX];
bool visited[MAX];

void dfs(int u) {
    visited[u] = true;
    for (int v : grafo[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void dfs_visitar(int V) {
    int num = 0;
    for (int i = 1; i <= V; i++) {
        if (!visited[i]) {
            num++;
            dfs(i);
        }
    }
    cout << num << endl;
}

int main() {
    int TC, V;
    char c, a, b;
    string input;

    cin >> TC;
    while (TC--) {
        fill(begin(visited), end(visited), false);
        cin >> c;
        V = c - '0' - 16;
        cin.ignore();

        while (getline(cin, input) && input.length() > 1) {
            stringstream ss(input);
            ss >> a >> b;
            int u = a - '0' - 16;
            int v = b - '0' - 16;
            grafo[u].push_back(v);
            grafo[v].push_back(u);
        }

        dfs_visitar(V);
        if (TC) cout << endl;

        for (int i = 0; i < MAX; i++) {
            grafo[i].clear();
        }
    }

    return 0;
}

