#include <iostream>
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
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        dfs(root, 0, res);
        return res;
    }
    void dfs(TreeNode* root, int p, int& res) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            // leave
            res = res + p * root->val;
            return;
        }
        dfs(root->left, 1, res);
        dfs(root->right, 0, res);
    }
};
