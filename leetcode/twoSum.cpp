#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			for (auto ind = nums.begin(); ind != nums.end(); ind++) {
				auto t = find(ind + 1, nums.end(), target - *ind);	
				if (t != nums.end())
					return vector<int> {static_cast<int>(ind - nums.begin()), static_cast<int>(t - nums.begin())};
			}
			return vector<int> {0, 0};
		}
};

int main() {
	Solution solution;
	vector<int> a{3, 1, 2, 1, 5};
	auto res = solution.twoSum(a, 5);
	cout << res[0] << res[1];
}
