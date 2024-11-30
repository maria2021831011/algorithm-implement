
#include <bits/stdc++.h>
using namespace std;

const int max_node = 1000;
vector<int> graph[max_node];              // Corrected: 2D vector for adjacency list
vector<int> transpose_graph[max_node];    // Corrected: Transpose graph as 2D vector
bool vis[max_node];
stack<int> st;

// Function to perform DFS and store nodes in the stack in finishing order
void dfs(int n) {
    if (vis[n]) return;

    vis[n] = true;
    for (int neighbor : graph[n]) {       // Enhanced for-loop for better readability
        if (!vis[neighbor]) {
            dfs(neighbor);
        }
    }
    st.push(n);                           // Push current node after exploring all neighbors
}

// Function to perform DFS on the transposed graph and print SCC
void dfs_print(int n) {
    if (vis[n]) return;

    cout << n << " ";
    vis[n] = true;
    for (int neighbor : transpose_graph[n]) {   // Loop through the transpose graph
        if (!vis[neighbor]) {
            dfs_print(neighbor);
        }
    }
}

// Kosaraju's algorithm to find and print all SCCs
int kosarajuSCC(int numberOfNodes) {
    int scc_count = 0;

    // Step 1: Order nodes based on their finish time in original graph
    for (int i = 0; i < numberOfNodes; i++) {
        if (!vis[i]) {
            dfs(i);
        }
    }

    // Step 2: Reset visited array for second DFS on transposed graph
    fill(vis, vis + numberOfNodes, false);

    // Step 3: Process nodes in order of decreasing finish time
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]) {
            dfs_print(node);     // Print one SCC
            scc_count++;
            cout << endl;
        }
    }

    return scc_count;
}

int main() {
    int numberOfNodes, numberOfEdges, u, v;
    cin >> numberOfNodes >> numberOfEdges;

    // Initialize graphs and visited array
    for (int i = 0; i < numberOfNodes; i++) {
        vis[i] = false;
        graph[i].clear();
        transpose_graph[i].clear();
    }

    // Read the edges
    for (int i = 0; i < numberOfEdges; i++) {
        cin >> u >> v;
        graph[u].push_back(v);            // Original graph edge
        transpose_graph[v].push_back(u);  // Transposed graph edge
    }

    // Find and print SCCs
    int components = kosarajuSCC(numberOfNodes);
    cout << "Components: " << components << endl;

    return 0;
}
