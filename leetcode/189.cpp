#include <vector>
#include <iostream>

using namespace std;

class Solution {
	public:
	void rotate(vector<int>& nums, int k) {
		k = k % nums.size();
		if (k == 0) return;
		reverse(nums.begin(), nums.end());
		reverse(nums.begin(), nums.begin() + k);	
		reverse(nums.begin() + k, nums.end());
	}
};

int main() {
	Solution a = Solution();
	vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
	a.rotate(nums, 3);
	for (auto x: nums) {
		cout << x << " ";
	}
}


