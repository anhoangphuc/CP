#include <iostream>
#include <vector>

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
        vector<int> rightSideView(TreeNode* root) {
            vector<int> res = {};    
            dfs(root, 0, res);
            return res;
        }

        void dfs(TreeNode* root, int height, vector<int>& res) {
            if (root == NULL) return;
            if (height == res.size()) {
                res.push_back(root->val);
            }
            dfs(root->right, height + 1, res);
            dfs(root->left, height + 1, res);
        }
};

int main() {
    return 0;
}
