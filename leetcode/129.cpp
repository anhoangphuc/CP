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
		int sumNumbers(TreeNode* root) {
			int res = 0;
			if (root == NULL) return res;
			traverseTree(root, root->val, &res);
			return res;
		}

		void traverseTree(TreeNode* root, int cur, int* res) {
			if (root->left == NULL && root->right == NULL) {
				*res = *res + cur;
				return;
			}
			if (root->left != NULL)
				traverseTree(root->left, cur * 10 + root->left->val, res);
			if (root->right != NULL)
				traverseTree(root->right, cur * 10 + root->right->val, res);
		}
};

int main() {
	return 0;
}
