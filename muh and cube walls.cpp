#include <iostream>
#define MAX 200002
using namespace std;

int n, w, t[MAX], p[MAX], b[MAX], ans;

void kmp() {
    int i = 0, j = -1;
    b[0] = -1;
    while (i < w) {
        while (j >= 0 && p[i] != p[j]) j = b[j];
        i++, j++;
        b[i] = j;
    }
}

void kmpsearch() {
    int i = 0, j = 0;
    while (i < n) {
        if (t[i] == p[j] || j == -1) {
            i++, j++;
            if (j == w) {
                ans++;
                j = b[j];
            }
        } else {
            j = b[j];
        }
    }
}

int main() {
    cin >> n >> w;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    for (int i = 0; i < w; ++i) {
        cin >> p[i];
    }
    if (w == 1) {
        cout << n << endl;
        return 0;
    }

    for (int i = 1; i < n; ++i) {
        t[i - 1] = t[i] - t[i - 1];
    }
    n--;
    for (int i = 1; i < w; ++i) {
        p[i - 1] = p[i] - p[i - 1];
    }
    w--;

    kmp();
    kmpsearch();
    cout << ans << endl;

    return 0;
}


