#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL) return NULL;
        TreeNode* leftResult = inorderSuccessor(root->left, p);
        if (leftResult != NULL) return leftResult;
        if (p->val < root->val) return root;
        TreeNode* rightResult = inorderSuccessor(root->right, p);
        if (rightResult != NULL) return rightResult;
        return NULL;
    }
};
