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
		TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            return buildTree(preorder, inorder, 0, preorder.size(), 0, inorder.size());
            
		}
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int left1, int right1, int left2, int right2) {
            if (right1 - left1 == 0) return NULL;
            if (right1 - left1 == 1) {
                return new TreeNode(preorder[left1]);
            }
            TreeNode* rootNode = new TreeNode(preorder[left1]);
            int i;
            for (i = left2; i < right2; i++) {
                if (inorder[i] == preorder[left1]) break;
            }
            int leftBreak = left1 + 1 + i - left2;
            rootNode->left = buildTree(vector<int>& preorder, vector<int>& inorder, left1 + 1, leftBreak, left2, i);
            rootNode->right = buildTree(vector<int>& preorder, vector<int>& inorder, leftBreak, right                TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            return buildTree(preorder, inorder, 0, preorder.size(), 0, inorder.size());

                }
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int left1, int right1, int left2, int right2) {
            if (right1 - left1 == 0) return NULL;
            if (right1 - left1 == 1) {
                return new TreeNode(preorder[left1]);
            }
            TreeNode* rootNode = new TreeNode(preorder[left1]);
            int i;
            for (i = left2; i < right2; i++) {
                if (inorder[i] == preorder[left1]) break;
            }
            int leftBreak = left1 + 1 + i - left2;
            rootNode->left = buildTree(preorder, inorder, left1 + 1, leftBreak, left2, i);
            rootNode->right = buildTree(preorder, inorder, leftBreak, right1, i + 1, right2);
            return rootNode;
        }1, i + 1, right2);
            return rootNode;
        }
};

int main() {
	return 0;
}

