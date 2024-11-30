
#include <bits/stdc++.h>

using namespace std;

int n;
int sg[1010101];
vector<int> sg_pos[1010];

bool found(int v, int l, int r) {
    auto it = lower_bound(sg_pos[v].begin(), sg_pos[v].end(), l);
    if (it == sg_pos[v].end())
        return false;
    if ((*it) <= r)
        return true;
    return false;
}

int main() {
    for (int i = 0; i < 1010; i++)
        sg_pos[i].clear();

    for (int i = 1; i < 1010101; i++) {
        sg[i] = 0;
        int l = ceil(sqrt(sqrt(i)));
        int r = sqrt(i);
        if (r >= i)
            r = i - 1;
        while (found(sg[i], l, r))
            sg[i]++;
        sg_pos[sg[i]].push_back(i);
    }

    int ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        long long v;
        scanf("%lld", &v);
        int t = 0;
        int l = ceil(sqrt(sqrt(v)));
        int r = sqrt(v);
        if (r >= v)
            r = v - 1;
        while (found(t, l, r))
            t++;
        ans ^= t;
    }

    if (ans != 0)
        printf("Furlo\n");
    else
        printf("Rublo\n");

    return 0;
}
