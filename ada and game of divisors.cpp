#include <bits/stdc++.h>
using namespace std;
const int MAX = 20000005;
int t,n;
int lp[MAX], sigma[MAX], dp[MAX], dpSum[MAX];
int main() {

    for (int i = 2; i * i < MAX; i++) {
        if (lp[i]) continue;
        for (int j = i; j < MAX; j += i) lp[j] = i;
    }
    cerr<< 1.0 * clock() / CLOCKS_PER_SEC << endl;
    for (int i = 2; i < MAX; i++) {
        if (!lp[i]) lp[i] = i;
    }
    sigma[1] = 1;
    for (int i = 2; i < MAX; i++) {
        int counter = 0, j = i;
        while (j % lp[i] == 0) {
            counter++;
            j /= lp[i];
        }
        sigma[i] = sigma[j] * (counter + 1);
    }
    cerr  << 1.0 * clock() / CLOCKS_PER_SEC << endl;
    dp[0] = 0;
    for (int i = 1; i < MAX; i++) {
        int low = i - sigma[i];
        if (low == 0 || dpSum[i - 1] - dpSum[low - 1] != sigma[i]) dp[i] = 1;
        else dp[i] = 0;
        dpSum[i] = dpSum[i - 1] + dp[i];
    }
    cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);

        puts(dp[n] == 0 ? "Vinit" : "Ada");
    }

    return 0;
}

