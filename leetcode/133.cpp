#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    unordered_map<Node*, Node*> m;
    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;
        if (m.find(node) != m.end()) return m[node];
        auto res = new Node(node->val);
        m[node] = res;
        for (auto neighbor : node->neighbors) {
            res->neighbors.push_back(cloneGraph(neighbor));
        }
        return res;
    }
};
