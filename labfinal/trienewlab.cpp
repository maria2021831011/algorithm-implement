#include <bits/stdc++.h>
using namespace std;

struct Trie {
    Trie* child[26];
    bool isend;

    Trie() {
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
        isend = false;
    }
};

void insert(Trie* root, string key) {
    Trie* curr = root;
    for (char c : key) {
        if (curr->child[c - 'a'] == nullptr) {
            curr->child[c - 'a'] = new Trie();
        }
        curr = curr->child[c - 'a'];
    }
    curr->isend = true;
}

bool search(Trie* root, string key) {
    Trie* curr = root;
    for (char c : key) {
        if (curr->child[c - 'a'] == nullptr) {
            return false;
        }
        curr = curr->child[c - 'a'];
    }
    return curr->isend;
}

int main() {
    int n;
    cin >> n;
    string s1;
    cin >> s1;
    string s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    Trie* root = new Trie();
    for (int i = 0; i < n; i++) {
        insert(root, s[i]);
    }
    cout << search(root, s1);
    return 0;
}
