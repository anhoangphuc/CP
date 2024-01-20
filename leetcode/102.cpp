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

class Solution {
    public:
        queue<TreeNode*> q;
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> res = {};
            if (root == NULL) return {};
            q.push(root);
            while (!q.empty()) {
                int n = q.size();
                vector<int> valueThisLevel = {};
                while (n-- > 0) {
                    TreeNode* cur = q.front();
                    valueThisLevel.push_back(cur->val);
                    q.pop();
                    if (cur->left != NULL) q.push(cur->left);
                    if (cur->right != NULL) q.push(cur->right);
                }
                res.push_back(valueThisLevel);
            }
            return res;
        }
};

int main() {
    return 0;
}
