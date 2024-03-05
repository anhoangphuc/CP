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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* p = new TreeNode(100001);
        p->left = root;
        auto result = dfs(root, p, true, key);
        if (result.first == NULL)
            return p->left;
        else {
            auto pivot = result.second;
            while (pivot->left != NULL)
                pivot = pivot->left;
            pivot->left = result.first;
        }
        return p->left;
    }
    pair<TreeNode*, TreeNode*> dfs(TreeNode* root, TreeNode* parent,
                                   bool isLeft, int key) {
        if (root == NULL)
            return {NULL, NULL};
        if (root->val == key) {
            if (root->left == NULL) {
                if (isLeft)
                    parent->left = root->right;
                else
                    parent->right = root->right;
                return {NULL, root->right};
            } else if (root->right == NULL) {
                if (isLeft)
                    parent->left = root->left;
                else
                    parent->right = root->left;
                return {NULL, root->left};
            } else {
                // both child != null
                if (isLeft)
                    parent->left = root->right;
                else
                    parent->right = root->right;
                return {root->left, root->right};
            }
        } else if (root->val > key) {
            return dfs(root->left, root, true, key);
        } else {
            return dfs(root->right, root, false, key);
        }
    }
};
