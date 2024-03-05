#include <vector>
#include <string>
using namespace std;
class Trie {
public:
    vector<Trie*> v{30};
    bool isWord;
    bool isPrefix;
    Trie() {
        isWord = false;
        isPrefix = false;
    }

    void insert(string word) {
        auto node = this;
        for (auto x : word) {
            if (node->v[x - 'a'] == NULL) {
                node->v[x - 'a'] = new Trie();
            }
            node = node->v[x - 'a'];
            node->isPrefix = true;
        }
        node->isWord = true;
    }

    bool search(string word) {
        auto node = this;
        for (auto x : word) {
            if (node->v[x - 'a'] == NULL)
                return false;
            node = node->v[x - 'a'];
        }
        return node->isWord;
    }

    bool startsWith(string prefix) {
        auto node = this;
        for (auto x : prefix) {
            if (node->v[x - 'a'] == NULL)
                return false;
            node = node->v[x - 'a'];
        }
        return node->isPrefix;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
