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
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>> res = {};
            if (root == NULL) return {};
            q.push(root);
            int cnt = 0;
            while (!q.empty()) {
                int n = q.size();
                cnt += 1;
                vector<int> valueThisLevel = {};
                while (n-- > 0) {
                    TreeNode* cur = q.front();
                    valueThisLevel.push_back(cur->val);
                    q.pop();
                    if (cur->left != NULL) q.push(cur->left);
                    if (cur->right != NULL) q.push(cur->right);
                }
                if (cnt % 2 == 0)
                reverse(valueThisLevel.begin(), valueThisLevel.end());
                res.push_back(valueThisLevel);
            }
            return res;
        }
};

int main() {
    return 0;
}
