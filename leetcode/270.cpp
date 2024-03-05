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
    int closestValue(TreeNode* root, double target) {
        if (root->left == NULL && root->right == NULL) return root->val;
        auto res = root->val;
        if (root->left != NULL && target < root->val) {
            int leftResult = closestValue(root->left, target);
            res = getResult(res, leftResult, target);
        }
        if (root->right != NULL && target > root->val) {
            int rightResult = closestValue(root->right, target);
            res = getResult(res, rightResult, target);
        }
        return res;
    }

    int getResult(int x, int y, double target) {
        if (x == target) return x;
        if (y == target) return y;
        if (x > target) {
            if (y > target) { return min(x, y); }
            else if (x + y > 2 * target) return y;
            else if (x + y == 2 * target) return min(x, y);
            return x;
        } else {
            if (y < target) { return max(x, y); }
            else if (2 * target > x + y) return y;
            else if (2 * target == x + y) return min(x, y);
            return x;
        }
        return x;
    }
};


