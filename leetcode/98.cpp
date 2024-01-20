#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {;
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

struct TreeResult {
    bool isValid;
    int minValue;
    int maxValue;
    TreeResult(bool isValid, int minValue, int maxValue): isValid(isValid), minValue(minValue), maxValue(maxValue) {}
};

class Solution {
    public:
        bool isValidBST(TreeNode* root) {
            if (root == NULL) return true;
            TreeResult res = traverse(root);
            return res.isValid;
        }

        TreeResult traverse(TreeNode* root) {
            int minValue = root->val;
            int maxValue = root->val;
            bool isValid = true;
            if (root->left != NULL) {
                TreeResult left = traverse(root->left);
                isValid = isValid && left.isValid && (root->val > left.maxValue);
                minValue = min(minValue, left.minValue);
                maxValue = max(maxValue, left.maxValue);
            }
            if (root->right != NULL) {
                TreeResult right = traverse(root->right);
                isValid = isValid && right.isValid && root->val < right.minValue;
                minValue = min(minValue, right.minValue);
                maxValue = max(maxValue, right.maxValue);
            }
            return TreeResult(isValid, minValue, maxValue);
        }

};

int main() {
    return 0;
}
