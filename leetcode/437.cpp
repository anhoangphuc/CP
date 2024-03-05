#include <map>
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
    int pathSum(TreeNode* root, int targetSum) {
        map<long long int, int> m;
        int res = 0;
        m[0] = 1;
        dfs(root, targetSum, 0, m, res);
        return res;
    }
    void dfs(TreeNode* root, int targetSum, long long int currentSum, map<long long int, int>& m, int& res) {
        if (root == NULL) return;
        //cout << "LEAF VALUE " << root->val << " " << currentSum << " " << m[currentSum + root->val - targetSum] << endl;
        res += m[currentSum + root->val - targetSum];
        m[currentSum + root->val] += 1;
        dfs(root->left, targetSum, currentSum + root->val, m, res);
        dfs(root->right, targetSum, currentSum + root->val, m, res);
        m[currentSum + root->val] -= 1;
    }
};
