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
    int countNodes(TreeNode* root) {
        int depth = countDepth(root);
        int left = 1;
        if (depth == 0) return 0;
        int right = 1 << (depth - 1);
        int i = left;
        int j = right;
        int res(-1);
        while (i <= j) {
            int mid = (i + j) / 2;
            if (isExist(root, mid, left, right)) {
                i = mid + 1;
            } else {
                res = mid;
                j = mid - 1;
            }
        }
        if (res == -1)
            return ((1 << depth) - 1);
        else
            return (1 << (depth - 1)) - 1 + res - 1;
    }

    bool isExist(TreeNode* root, int mid, int left, int right) {
        if (left == right) {
            return (root != NULL);
        }
        int v = (left + right) / 2;
        if (mid <= v)
            return isExist(root->left, mid, left, v);
        else
            return isExist(root->right, mid, v + 1, right);
    }

    int countDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        return 1 + countDepth(root->left);
    }
};
