#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
	public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> res = {};		
		sort(nums.begin(), nums.end());
		do {
			if (res.size() == 0) {
				res.push_back(nums);
			} else {
				auto cur = res.back();
				if (!cmp(cur, nums)) {
					res.push_back(nums);
				}
			}
		} while (next_permutation(nums.begin(), nums.end()));
		return res;
	}
	bool cmp(vector<int>& v1, vector<int>& v2) {
		for (auto i = 0; i < v1.size(); i++) {
			if (v1[i] != v2[i]) {
				return false;
			}
		}
		return true;
	}
};

int main() {
	Solution a = Solution();
	vector<int> b = {3, 3, 3, 4};
	auto res = a.permuteUnique(b);
	for (auto r: res) {
		for (auto v: r) {
			cout << v << " ";
		}
		cout << endl;
	}
}
