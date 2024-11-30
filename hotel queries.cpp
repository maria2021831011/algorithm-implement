#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200011;
int tree[4 * MAXN];  // Store the maximum value in the segment tree
int indexTree[4 * MAXN];  // Store the index corresponding to the maximum value

void build(int a[], int v, int s, int e) {
    if (s == e) {
        tree[v] = a[s];
        indexTree[v] = s + 1;  // Store the 1-based index
        return;
    }
    int mid = (s + e) / 2;
    build(a, 2 * v, s, mid);
    build(a, 2 * v + 1, mid + 1, e);
    if (tree[2 * v] >= tree[2 * v + 1]) {
        tree[v] = tree[2 * v];
        indexTree[v] = indexTree[2 * v];
    } else {
        tree[v] = tree[2 * v + 1];
        indexTree[v] = indexTree[2 * v + 1];
    }
}

int query(int v, int tl, int tr, int num) {
    if (tree[v] < num) return 0;
    if (tl == tr) {
        tree[v] -= num;
        return indexTree[v];
    }
    int mid = (tl + tr) / 2;
    int idx;
    if (tree[2 * v] >= num) {
        idx = query(2 * v, tl, mid, num);
    } else {
        idx = query(2 * v + 1, mid + 1, tr, num);
    }
    if (tree[2 * v] >= tree[2 * v + 1]) {
        tree[v] = tree[2 * v];
        indexTree[v] = indexTree[2 * v];
    } else {
        tree[v] = tree[2 * v + 1];
        indexTree[v] = indexTree[2 * v + 1];
    }
    return idx;
}

int main() {
    int n, m;
    cin >> n >> m;
    int h[n], r[m];
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < m; i++)
        cin >> r[i];

    build(h, 1, 0, n - 1);

    for (int i = 0; i < m; i++)
        cout << query(1, 0, n - 1, r[i]) << " ";

    return 0;
}
