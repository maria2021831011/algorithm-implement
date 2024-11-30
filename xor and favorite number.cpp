#include <bits/stdc++.h>
using namespace std;
const int BLOCK_SIZE = 316;
struct Query {
    int left, right, number;
};
int cnt[1 << 20];
long long result = 0;
int favourite;

bool compare(const Query &x, const Query &y) {
    if (x.left / BLOCK_SIZE != y.left / BLOCK_SIZE)
        return x.left / BLOCK_SIZE < y.left / BLOCK_SIZE;
    return x.right < y.right;
}

void add(int v) {
    result += cnt[v ^ favourite];
    cnt[v]++;
}

void del(int v) {
    cnt[v]--;
    result -= cnt[v ^ favourite];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, m;
    cin >> n >> m >> favourite;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] ^ a[i - 1];
    }

    vector<Query> queries(m);
    for (int i = 0; i < m; i++) {
        int left, right;
        cin >> left >> right;
        left--; right++;
        queries[i] = Query{left, right, i};
    }

    sort(queries.begin(), queries.end(), compare);

    vector<long long> answer(m);

    int currL = 0, currR = 0;

    for (int i = 0; i < m; i++) {
        int L = queries[i].left, R = queries[i].right;

        while (currR < R) {
            add(pref[currR]);
            currR++;
        }
        while (currR > R) {
            currR--;
            del(pref[currR]);
        }
        while (currL < L) {
            del(pref[currL]);
            currL++;
        }
        while (currL > L) {
            currL--;
            add(pref[currL]);
        }

        answer[queries[i].number] = result;
    }

    for (auto ans : answer) {
        cout << ans << '\n';
    }

    return 0;
}

