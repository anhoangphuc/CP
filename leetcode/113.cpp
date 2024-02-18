#include <vector>

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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
	vector<vector<int>> v;
	dfs(root, 0, {}, v, targetSum);
	return v;
    }

    void dfs(TreeNode* root, int curSum, vector<int> curV, vector<vector<int>>& v, int target) {
	if (root == NULL) return;
	if (root->left == NULL && root->right == NULL) {
		if (curSum + root->val != target) return;
		curV.push_back(root->val);
		v.push_back(curV);
		return;
	}
	curV.push_back(root->val);
	if (root->left) dfs(root->left, curSum + root->val, curV, v, target);
	curV.pop_back();
	
	curV.push_back(root->val);
	if (root->right) dfs(root->right, curSum + root->val, curV, v, target);
	curV.pop_back();
    }
};

int main() {
	return 0;
}
