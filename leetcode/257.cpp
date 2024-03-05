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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == NULL)
            return {};
        vector<string> res = {};
        dfs(root, res, "");
        return res;
    }
    void dfs(TreeNode* root, vector<string>& res, string cur) {
        if (root->left == NULL && root->right == NULL) {
            res.push_back(helper(cur) + to_string(root->val));
            return;
        }
        if (root->left != NULL)
            dfs(root->left, res, helper(cur) + to_string(root->val));
        if (root->right != NULL)
            dfs(root->right, res, helper(cur) + to_string(root->val));
    }
    string helper(string x) {
        return x == "" ? "" : x + "->";
    }
};
