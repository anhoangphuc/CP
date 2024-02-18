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
	void recoverTree(TreeNode* root) {
		vector<TreeNode*> v;
		dfs(root, v);
		TreeNode* w1 = NULL;
		TreeNode* w2 = NULL;
		for (int i = 0; i < v.size(); i++) {
			if ((i > 0 && v[i]->val < v[i - 1]->val) || (i < v.size() -1 && v[i]->val > v[i + 1]->val)) {
				// This is wrong node
				if (w1 == NULL) w1 = v[i];
				else w2 = v[i];
			}
		}
		auto tmp = w1->val;
		w1->val = w2->val;
		w2->val = tmp;
	}
	void dfs(TreeNode* root, vector<TreeNode*>& v) {
		if (root == NULL) return;
		dfs(root->left, v);
		v.push_back(root);
		dfs(root->right, v);
	}
};

int main() {
	return 0;
}


