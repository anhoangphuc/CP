#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class BSTIterator {
	public:
		stack<TreeNode*> st;
		BSTIterator(TreeNode* root) {
			traverseLeft(root);
		}
		void traverseLeft(TreeNode* root) {
			while (root != NULL) {
				st.push(root);
				root = root->left;
			}
		}

		int next() {
			auto node = st.top();
			st.pop();
			traverseLeft(node->right);
			return node->val;
		}
		bool hasNext() {
			return !st.empty();
		}
};

int main() {
	return 0;
}
