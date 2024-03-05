#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        Node* first = NULL;
        Node* last = NULL;
        Node* pre = NULL;
        if (root == NULL) return NULL;
        dfs(root, pre, first, last);
        first->left = last;
        last->right = first;
        return first;
    }
    void dfs(Node* root, Node*& pre, Node*& first, Node*& last) {
        if (root == NULL)
            return;
        dfs(root->left, pre, first, last);
        last = root;
        if (first == NULL)
            first = root;
        if (pre != NULL) {
            pre->right = root;
            root->left = pre;
        }
        pre = root;
        dfs(root->right, pre, first, last);
    }
};
