
#include <bits/stdc++.h>
using namespace std;

const int mx = 100001;
int grandy[mx];
vector<int> divisors[mx];

void sieve() {
    for(int i = 2; i < mx; i++) {
        for(int j = i; j < mx; j += i) {
            divisors[j].push_back(i);
        }
    }
}

int sg(int X) {
    if(X == 1) {
        return 0;
    }
    if(grandy[X] != -1) {
        return grandy[X];
    }
    set<int> s;
    for(int i = 0; i < divisors[X].size(); i++) {
        int Y = divisors[X][i];
        int Z = X / Y;
        if(Y % 2 == 0)
            s.insert(0);
        else
            s.insert(sg(Z));
    }
    int mex = 0;
    while(s.find(mex) != s.end()) mex++;
    grandy[X] = mex;
    return grandy[X];
}

int main() {
    sieve();
    int n;
    memset(grandy, -1, sizeof(grandy));
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> n;
        int ans = 0, h;
        for(int i = 1; i <= n; ++i) {
            cin >> h;
            ans ^= sg(h);
        }
        if(ans)
            cout << "1" << endl;
        else
            cout << "2" << endl;
    }
    return 0;
}
