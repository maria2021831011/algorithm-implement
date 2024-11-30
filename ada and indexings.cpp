
#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct trie {
    struct trie* arr[26];
    ll count;
    trie()
    {
        for(int i=0;i<26;i++)
        {
            arr[i]=nullptr;
        }
        count=0;
    }
};



void add(trie *root, string s) {
    ll len = s.length();
    if (len == 0)
        return;
        trie* newn=root;
    for (ll index = 0; index < len; index++) {
        if (newn->arr[s[index] - 'a'] == NULL)
            newn->arr[s[index] - 'a'] = new trie();
        newn = newn->arr[s[index] - 'a'];
        newn->count++;
    }
}

ll find(trie *root, string s) {
    ll len = s.length();
    if (len == 0)
        return 0;
        trie* newn=root;
    for (ll index = 0; index < len; index++) {
        if (newn->arr[s[index] - 'a'] == NULL)
            return 0;
        newn = newn->arr[s[index] - 'a'];
    }
    return newn->count;
}

int main() {
    ll n, q;
    cin >> n >> q;
    trie *root = new trie();
    while (n--) {
        string s;
        cin >> s;
        ll len = s.length();
        if (len >= 1)
            add(root, s);
    }
    while (q--) {
        string s;
        cin >> s;
        cout << find(root, s) << endl;
    }
    return 0;
}
