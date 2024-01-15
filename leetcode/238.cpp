#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> res(nums.size());
		res[0] = 1;
		for (int i = 1; i < nums.size(); i++) {
			res[i] = res[i - 1] * nums[i - 1];
		}
		int tmp = 1;
		for (int i = nums.size() - 1; i >= 0; i--) {
			res[i] = res[i] * tmp;
			tmp *= nums[i];
		}
		return res;
	}
};

int main() {
	Solution a = Solution();
	vector<int> nums {1, 2, 3, 4};
	vector<int> res = a.productExceptSelf(nums);
	for (auto x:res) {
		cout << x << " ";
	}
}
