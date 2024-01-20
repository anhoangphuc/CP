/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int res = 1000000;
        int cur = k;
        traverseTree(root, k, res);
        return res;
    }

    void traverseTree(TreeNode* root, int& cur, int&res) {
        if (root == NULL) return;
        if (cur < 0) return;
        traverseTree(root->left, cur, res);
        cur -= 1;
        if (cur == 0) {
            res = root->val;
            return;
        }
        traverseTree(root->right, cur, res);
    }
};
