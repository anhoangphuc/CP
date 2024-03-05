#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return constructHelper(preorder, 0, preorder.size() - 1);
    }
    TreeNode* constructHelper(vector<int>& preorder, int left, int right) {
        //cout << left << " " << right << endl;
        if (left > right)
            return NULL;
        if (left == right)
            return new TreeNode(preorder[left]);
        TreeNode* node = new TreeNode(preorder[left]);
        int pivot = right + 1;
        for (int i = left + 1; i <= right; i++)
            if (preorder[i] > preorder[left]) {
                pivot = i;
                break;
            }
        node->left = constructHelper(preorder, left + 1, pivot - 1);
        node->right = constructHelper(preorder, pivot, right);
        return node;
    }
};
