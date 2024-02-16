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
    TreeNode* convertBST(TreeNode* root) { 
        int prev = 0;
        convertHelper(root, prev); 
        return root;
    }
    void convertHelper(TreeNode* root, int& prev) {
        if (root == NULL)
            return;
        convertHelper(root->right, prev);
        root->val = root->val + prev;
        prev = root->val;
        convertHelper(root->left, prev);
    }
};
