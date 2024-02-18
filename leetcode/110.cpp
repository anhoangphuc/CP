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
    bool isBalanced(TreeNode* root) {
        auto result = balanceHelper(root);
        return result.first;
    }

    pair<bool, int> balanceHelper(TreeNode* root) {
        if (root == NULL)
            return {true, 0};
        auto leftResult = balanceHelper(root->left);
        auto rightResult = balanceHelper(root->right);
        if (!leftResult.first || !rightResult.first ||
            abs(leftResult.second - rightResult.second) > 1) {
            return {false, 0};
        } else
            return {true, 1 + max(leftResult.second, rightResult.second)};
    }
};
