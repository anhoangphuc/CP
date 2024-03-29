#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v = {};
        dfs(root, v);
        return v;  
    }
    void dfs(TreeNode* root, vector<int>& v) {
        if (root == NULL) return;
        v.push_back(root->val);
        dfs(root->left, v);
        dfs(root->right, v);
    }
};
