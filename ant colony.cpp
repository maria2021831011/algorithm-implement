
#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 100005;
int arr[MAX_N];
int gcdTree[4 * MAX_N];
int countTree[4 * MAX_N];

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void build(int node, int start, int end) {
    if (start == end) {
        gcdTree[node] = arr[start];
        countTree[node] = 1;
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        gcdTree[node] = gcd(gcdTree[2 * node], gcdTree[2 * node + 1]);
        countTree[node] = 0;
        if (gcdTree[node] == gcdTree[2 * node])
            countTree[node] += countTree[2 * node];
        if (gcdTree[node] == gcdTree[2 * node + 1])
            countTree[node] += countTree[2 * node + 1];
    }
}

pair<int, int> query(int node, int start, int end, int l, int r) {
    if (r < start || end < l)
        return {0, 0};
    if (l <= start && end <= r)
        return {gcdTree[node], countTree[node]};
    int mid = (start + end) / 2;
    auto left = query(2 * node, start, mid, l, r);
    auto right = query(2 * node + 1, mid + 1, end, l, r);
    int resultGCD = gcd(left.first, right.first);
    int resultCount = 0;
    if (resultGCD == left.first)
        resultCount += left.second;
    if (resultGCD == right.first)
        resultCount += right.second;
    return {resultGCD, resultCount};
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    build(1, 1, n);
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        auto result = query(1, 1, n, l, r);
        cout << r - l + 1 - result.second << endl;
    }
    return 0;
}
