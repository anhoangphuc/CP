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
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        dfs(root, v);
        return construct(v, 0, v.size() - 1);
    }
    void dfs(TreeNode* root, vector<int>& v) {
        if (root == NULL) return;
        dfs(root->left, v);
        v.push_back(root->val);
        dfs(root->right, v);
    }
    TreeNode* construct(vector<int> const &v, int left, int right) {
        if (left > right) return NULL;
        if (left == right) return new TreeNode(v[left]);
        int pivot = (left + right) / 2;
        TreeNode* node = new TreeNode(v[pivot]);
        node->left = construct(v, left, pivot - 1);
        node->right = construct(v, pivot + 1, right);
        return node;
    }
};
