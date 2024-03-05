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
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        auto leftResult = minDepth(root->left);
        auto rightResult = minDepth(root->right);
        if (root->left == NULL && root->right == NULL)
            return 1;
        else if (root->left == NULL && root->right != NULL)
            return 1 + rightResult;
        else if (root->left != NULL && root->right == NULL)
            return 1 + leftResult;
        else
            return 1 + min(leftResult, rightResult);
    }
};	

