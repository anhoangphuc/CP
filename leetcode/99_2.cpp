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
	    TreeNode* pre = NULL;
    TreeNode* w1 = NULL;
    TreeNode* w2 = NULL; 
    void recoverTree(TreeNode* root) {
        dfs(root);
        auto tmp = w1->val;
        w1->val = w2->val;
        w2->val = tmp;
    }
    void dfs(TreeNode* root) {
        if (root == NULL)
            return;
        dfs(root->left);
        if (pre != NULL && root->val < pre->val) {
            if (w1 == NULL) {
                w1 = pre;
                w2 = root;
            }
            else
                w2 = root;
        }
        pre = root;
        dfs(root->right);
    }
};

int main() {
	return 0;
}


