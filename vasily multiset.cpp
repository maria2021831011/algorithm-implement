#include <iostream>
using namespace std;
const int MAX_BITS = 30;
struct TrieNode {
    TrieNode* child[2];
    int count;
    TrieNode() { child[0] = child[1] = nullptr; count = 0; }
};

struct XORTrie {
    TrieNode* root;
    XORTrie() { root = new TrieNode(); }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = MAX_BITS; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->child[bit]) node->child[bit] = new TrieNode();
            node = node->child[bit];
            node->count++;
        }
    }

    void remove(int num) {
        TrieNode* node = root;
        for (int i = MAX_BITS; i >= 0; i--) {
            int bit = (num >> i) & 1;
            node = node->child[bit];
            node->count--;
        }
    }

    int maxXOR(int num) {
        TrieNode* node = root;
        int result = 0;
        for (int i = MAX_BITS; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int desired = 1 - bit;
            if (node->child[desired] && node->child[desired]->count > 0) {
                result |= (1 << i);
                node = node->child[desired];
            } else {
                node = node->child[bit];
            }
        }
        return result;
    }
};

int main() {
    int q;
    cin >> q;
    XORTrie trie;
    trie.insert(0);
    while (q--) {
        char type;
        int x;
        cin >> type >> x;
        if (type == '+') trie.insert(x);
        else if (type == '-') trie.remove(x);
        else cout << trie.maxXOR(x) << endl;
    }
}

