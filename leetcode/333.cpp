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
    int BASE = 10001;
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
    pair<pair<int, int>, int> dfs(TreeNode* root, int& res) {
        if (root == NULL)
            return {{-BASE, BASE}, 0};
        auto leftResult = dfs(root->left, res);
        auto rightResult = dfs(root->right, res);
        // cout << "VAL " << root->val << endl;
        // cout << leftResult.second << " " << rightResult.second << endl;
        // cout << leftResult.first.first << " " << leftResult.first.second << " " << rightResult.first.first << " " << rightResult.first.second << endl;
        if (root->val > leftResult.first.first &&
            root->val < rightResult.first.second && leftResult.second >= 0 &&
            rightResult.second >= 0) {
            res = max(res, 1 + leftResult.second + rightResult.second);
            return {{max(rightResult.first.first, root->val), min(leftResult.first.second, root->val)},
                    1 + leftResult.second + rightResult.second};
        } else {
            return {{max(max(leftResult.first.first, rightResult.first.first),
                         root->val),
                     min(min(leftResult.first.second, rightResult.first.second),
                         root->val)},
                    -1};
        }
    }
};
