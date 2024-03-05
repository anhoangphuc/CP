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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == NULL || root->left == NULL) return root;
        auto res = upsideDownBinaryTree(root->left);

        root->left->left = root->right;
        root->left->right = root;
        root->left = NULL;
        root->right = NULL;
        return res;
    }
};
