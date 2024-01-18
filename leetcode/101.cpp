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
		bool isSymmetric(TreeNode* root) {
            if (root == NULL) return true;
            return isSymmetricEqual(root->left, root->right); 
		}

        bool isSymmetricEqual(TreeNode* p, TreeNode *q) {
            if (p == NULL && q == NULL) return true;
            if (p == NULL && q != NULL) return false;
            if (p != NULL && q == NULL) return false;
            return (p->val == q->val && isSymmetricEqual(p->left, q->right) && isSymmetricEqual(p->right, q->left));
        }
};

int main() {
	return 0;
}

