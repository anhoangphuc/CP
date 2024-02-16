#include <iostream>
	
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
	public:
	int longestConsecutive(TreeNode* root) {
		auto res = longestHelper(root);
		return res.second;
	}
	pair<int, int> longestHelper(TreeNode* root) {
		// pair result: consecutive with current element - longest consecutive
		if (root == NULL) return {0, 0};
		auto leftResult = longestHelper(root->left);
		auto rightResult = longestHelper(root->right);
		int leftConsecutive = 1;
		if (root->left != NULL && root->val + 1 == root->left->val) 
			leftConsecutive = leftResult.first + 1;
		int rightConsecutive = 1;
		if (root->right != NULL && root->val + 1 == root->right->val)
			rightConsecutive = rightResult.first + 1;
		int consecutiveWithCurrent = max(leftConsecutive, rightConsecutive);
		int maxConsecutive = max(consecutiveWithCurrent, max(leftResult.second, rightResult.second));
		return {consecutiveWithCurrent, maxConsecutive};
	}
};

int main() {
	return 0;
}

