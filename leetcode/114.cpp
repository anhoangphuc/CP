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
		void flatten(TreeNode* root) {
			auto res = flatten_helper(root);
			root = res.first;
		}

		pair<TreeNode*, TreeNode*> flatten_helper(TreeNode* root) {
			auto res = make_pair(root, root);
			if (root == NULL) return res;
			auto leftPair = flatten_helper(root->left);
			auto rightPair = flatten_helper(root->right);
			// Nullify left child
			root->left = NULL;
			if (leftPair.first == NULL && rightPair.first == NULL) {
				return res;
			} else if (leftPair.first == NULL && rightPair.first != NULL) {
				root->right = rightPair.first;
				res.second = rightPair.second;
			} else if (leftPair.first != NULL && rightPair.first == NULL) {
				root->right = leftPair.first;
				res.second = leftPair.second;
			} else {
				root->right = leftPair.first;
				leftPair.second->right = rightPair.first;
				res.second = rightPair.second;
			}
			return res;
		}
};

int main() {
	return 0;
}
