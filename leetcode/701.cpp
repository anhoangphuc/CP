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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL)
            return new TreeNode(val);
        auto head = root;
        while (true) {
            if (val > head->val) {
                if (head->right == NULL) {
                    head->right = new TreeNode(val);
                    break;
                }
                head = head->right;
            } else {
                if (head->left == NULL) {
                    head->left = new TreeNode(val);
                    break;
                }
                head = head->left;
            }
        }
        return root;
    }
};
