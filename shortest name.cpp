#include <iostream>
#include <string>
using namespace std;

const int ALPHA = 26;

struct TrieNode {
    bool isEnd;
    TrieNode* children[ALPHA];
    int count;

    TrieNode() {
        isEnd = false;
        count = 0;
        for (int i = 0; i < ALPHA; i++) {
            children[i] = nullptr;
        }
    }
};

void insertTrie(TrieNode* root, string str) {
    TrieNode* current = root;
    for (char ch : str) {
        int idx = ch - 'a';
        if (!current->children[idx]) {
            current->children[idx] = new TrieNode();
        }
        current = current->children[idx];
        current->count++;
    }
    current->isEnd = true;
}

long long ans;

void dfs(TrieNode* node, int depth) {
    if (!node) return;

    for (int i = 0; i < ALPHA; i++) {
        if (node->children[i]) {
            dfs(node->children[i], depth + 1);
            if (node->count != 1 && node->children[i]->count == 1) {
                ans += depth;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        TrieNode* root = new TrieNode();

        while (n--) {
            string str;
            cin >> str;
            insertTrie(root, str);
        }

        ans = 0;
        dfs(root, 1);
        cout << ans << endl;
    }

    return 0;
}
