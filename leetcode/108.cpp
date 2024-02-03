#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(): val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x)	: val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

class Solution {
	public:
		TreeNode* sortedArrayToBST(vector<int>& nums) {
			return makeBST(nums, 0, nums.size());
		}

		TreeNode* makeBST(vector<int>& nums, int left, int right) {
			if (left >= right) return NULL;
			if (left + 1 == right) return new TreeNode(nums[left]);
			int mid = (left + right) / 2;
			TreeNode* leftNode = makeBST(nums, left, mid);	
			TreeNode* rightNode = makeBST(nums, mid + 1, right);
			return new TreeNode(nums[mid], leftNode, rightNode);
		}
}

int main() {
	return 0;
}
