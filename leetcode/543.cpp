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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res - 1;
    }
    int dfs(TreeNode* root, int& res) {
        if (root == NULL)
            return 0;
        auto leftResult = dfs(root->left, res);
        auto rightResult = dfs(root->right, res);
        res = max(res, leftResult + rightResult + 1);
        return max(leftResult, rightResult) + 1;
    }
};

int main() {
	return 0;
}
