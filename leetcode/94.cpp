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
	vector<int> inorderTraversal(TreeNode* root) {
		if (root == NULL) return {};
		auto leftResult = inorderTraversal(root->left);
		auto rightResult = inorderTraversal(root->right);
		leftResult.push_back(root->val);
		leftResult.insert(leftResult.end(), rightResult.begin(), rightResult.end());
		return leftResult;
	}
};

int main()  {
	return 0;
}
