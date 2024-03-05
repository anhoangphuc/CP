#include <vector>
#include <map>
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int, int> m;
        int maxCur = 0;
        dfs(root, m, maxCur);
        vector<int> res = {};
        for (auto x : m) {
            if (x.second == maxCur)
                res.push_back(x.first);
        }
        return res;
    }
    int dfs(TreeNode* root, map<int, int>& m, int& maxCur) {
        if (root == NULL)
            return 0;
        auto leftResult = dfs(root->left, m, maxCur);
        auto rightResult = dfs(root->right, m, maxCur);
        auto sum = leftResult + rightResult + root->val;
        m[sum] += 1;
        maxCur = max(maxCur, m[sum]);
        return sum;
    }
};
