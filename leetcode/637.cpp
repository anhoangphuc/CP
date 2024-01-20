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
    map<int, pair<long long, long long>> mp;
    vector<double> averageOfLevels(TreeNode* root) {
        if (root == NULL) return {};
        int maxHeight = 0;
        vector<double> res{};
        traverseTree(root, 0, maxHeight);
        for (int i = 0; i <= maxHeight; i++) {
            res.push_back(mp[i].second * 1.0 / mp[i].first);
        }
        return res;
    }

    void traverseTree(TreeNode* root, int height, int& maxHeight) {
        if (root == NULL)
            return;
        if (mp.find(height) == mp.end()) {
            mp[height] = {0, 0};
        }
        maxHeight = max(maxHeight, height);
        mp[height].first += 1;
        mp[height].second += root->val;
        traverseTree(root->left, height + 1, maxHeight);
        traverseTree(root->right, height + 1, maxHeight);
    }
};

int main() {
    return 0;
}
