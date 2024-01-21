#include <iostream>
#include <map>
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
		map<TreeNode*, pair<TreeNode*, int>> treeInfo;
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			if (root == p || root == q || root == NULL) return root;
			auto leftRes = lowestCommonAncestor(root->left, p, q);
			auto rightRes = lowestCommonAncestor(root->right, p, q);
			if (leftRes != NULL && rightRes != NULL)
				return root;
			else if (leftRes == NULL && rightRes != NULL)
				return rightRes;
			else if (leftRes != NULL && rightRes == NULL)
				return leftRes;
			else return NULL;
		}
};

int main() {
	return 0;
}
