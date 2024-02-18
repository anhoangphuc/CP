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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> v;
        dfs(root, v, 0);
        reverse(v.begin(), v.end());
        return v;
    }
    void dfs(TreeNode* root, vector<vector<int>>& v, int height) {
        if (root == NULL) return;
        if (v.size() == height)
            v.push_back({});
        v[height].push_back(root->val);
        dfs(root->left , v, height + 1);
        dfs(root->right, v, height + 1);
    }
};
