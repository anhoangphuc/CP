#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructHelper(nums, 0, nums.size() - 1);
    }
    TreeNode* constructHelper(vector<int>& nums, int left, int right) {
        if (left > right)
            return NULL;
        if (left == right)
            return new TreeNode(nums[left]);
        int pivot = left;
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] > nums[pivot]) {
                pivot = i;
            }
        }
        auto res = new TreeNode(nums[pivot]);
        res->left = constructHelper(nums, left, pivot - 1);
        res->right = constructHelper(nums, pivot + 1, right);
        return res;
    }
};
