#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};
class Solution {
public:
    int countUnivalSubtrees(TreeNode* root) {
        int sum = 0;
        countHelper(root, sum);
        return sum;
    }

    bool countHelper(TreeNode* root, int& sum) {
        if (root == NULL)
            return false;
        if (root->left == NULL && root->right == NULL) {
            sum += 1;
            return true;
        }
        int leftResult = countHelper(root->left, sum);
        int rightResult = countHelper(root->right, sum);
        if (root->left == NULL && root->right != NULL) {
            if (root->val == root->right->val && rightResult) {
                sum += 1;
                return true;
            } else
                return false;
        }

        if (root->left != NULL && root->right == NULL) {
            if (root->val == root->left->val && leftResult) {
                sum += 1;
                return true;
            } else
                return false;
        }
        if (root->val == root->left->val && root->val == root->right->val &&
            leftResult && rightResult) {
            sum += 1;
            return true;
        }
        return false;
    }
};
