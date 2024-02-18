#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
	public:
	vector<TreeNode*> generateTrees(int n) {
		vector<vector<TreeNode*>> dp(n + 1);
		dp[0].push_back(NULL);
		for (int numberOfNodes = 1; numberOfNodes <= n; numberOfNodes++) {
			for (int i = 1; i <= numberOfNodes; i++) {
				int j = numberOfNodes - i;
				for (auto left: dp[i - 1]) {
					for (auto right: dp[j]) {
						TreeNode* root = new TreeNode(i, left, clone(right, i));
						dp[numberOfNodes].push_back(root);
					} 		
				}
			}
		}
		return dp[n];
	}
	TreeNode* clone(TreeNode* root, int index) {
		if (root == NULL) return NULL;
		TreeNode* res = new TreeNode(root->val + index);
		res->left = clone(root->left, index);
		res->right = clone(root->right, index);
		return res;
	}
};

int main() {
	return 0;
}
