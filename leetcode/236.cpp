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
		map<TreeNode*, pair<TreeNode*, int>> treeInfo;
		TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
			treeInfo[root] = {NULL, 0};	
			buildTree(root);
			if (treeInfo[p].second < treeInfo[q].second) {
				TreeNode* tmp = p;
				p = q;
				q = tmp;
			}
			while (treeInfo[p].second > treeInfo[q].second) {
				p = treeInfo[p].first;
			}
			
			// Now p and q has same height;
			if (p == q) return p;
			while (true) {
				p = treeInfo[p].first;
				q = treeInfo[q].first;
				if (p == q) return p;
			}
			return root;
		}
		
		void buildTree(TreeNode* root) {
			if (root->left != NULL) {
				treeInfo[root->left] = {root, treeInfo[root] + 1};
				buildTree(root->left);
			}
			if (root->right != NULL) {
				treeInfo[root->right] = {root, treeInfo[root] + 1};
				buildTree(root->right);
			}
		}
};

int main() {
	return 0;
}
