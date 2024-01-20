/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int cur = 1000000;
        int res = 1000000;
        traverseInOrder(root, cur, res);
        return res;
    }

    void traverseInOrder(TreeNode* root, int& cur, int& res) {
        if (root == NULL) return;
        traverseInOrder(root->left, cur, res);
        if (cur == 1000000) {
            cur = root->val;
        } else {
            res = min(res, root->val - cur);
            cur = root->val;
        }
        traverseInOrder(root->right, cur, res);
    }
};
