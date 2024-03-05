#include <iostream>
#include <vector>
#include <map>
#include <queue>
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
    const int BASE = 103;
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>>  res;
        map<int, vector<int>> m;
        queue<pair<TreeNode*, int>> q;
        q.push({ root, BASE });
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node.first == NULL) continue;
            m[node.second].push_back(node.first->val);
            q.push({ node.first->left, node.second - 1});
            q.push({ node.first->right, node.second + 1});
        }
        for (auto i = 0; i < 2 * BASE; i++)
            if (!m[i].empty())
                res.push_back(m[i]);
        return res;
    }
};
