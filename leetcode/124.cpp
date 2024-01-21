#include <iostream>
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
		int maxPathSum(TreeNode* root) {
			auto res = maxHelper(root);
			return res.second;
		}

		pair<int, int> maxHelper(TreeNode* root) {
			if (root == NULL) return {0, 0};
			int maxRootValue = root->val;
			auto leftRes = maxHelper(root->left);
			auto rightRes = maxHelper(root->right);
			int maxFirst = max(leftRes.first, rightRes.first);
			if (maxFirst > 0) 
				maxRootValue += maxFirst;
			int maxValue = root->val;
			if (leftRes->first > 0)
				maxValue += leftRest->first;
			if (rightRes->first > 0)
				maxValue += rightRes->first;
			maxValue = max(maxValue, leftRes.second);
			maxValue = max(maxValue, rightRes.second);
			return {maxRootValue, maxValue};
		}
};

int main() {
	return 0;
}
