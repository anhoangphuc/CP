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
		TreeNode* invertTree(TreeNode* p) {
            if (p == NULL) return NULL;
            TreeNode* leftNode = p->left;
            TreeNode* rightNode = p->right;
            p->left = invertTree(rightNode);
            p->right = invertTree(leftNode);
            return p;
		}
};

int main() {
	return 0;
}

