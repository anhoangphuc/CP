#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
    public:
        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            return helper(inorder, postorder, 0, ssize(inorder), 0, ssize(inorder));
        }

        TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int l1, int r1, int l2, int r2) {
            if (l1 == r1) {
                return nullptr;
            }

            auto val = postorder[r2 - 1];
            auto it = find(inorder.begin() + l1, inorder.begin() + r1, val);
            TreeNode* root = new TreeNode(val);
            auto leftSize = it - (inorder.begin() + l1);
            root->left = helper(inorder, postorder, l1, l1 + leftSize, l2, l2 + leftSize);
            root->right = helper(inorder, postorder, l1 + leftSize + 1, r1, l2 + leftSize, r2 - 1);
            return root;
        }
};

int main() {
    Solution s = Solution();
    vector<int> inorder = { 9, 3, 15, 20, 7 };
    vector<int> postorder = { 9, 15, 7, 20, 3 };
    s.buildTree(inorder, postorder);
}
