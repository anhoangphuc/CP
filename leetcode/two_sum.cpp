#include <bits/stdc++.h>
using namespace std;


class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			sort(nums.begin(), nums.end());			
			for (auto ind = nums.begin(), ind != nums.end(), ind++) {
				if (binary_search(ind + 1, nums.end(), target - *ind))
			}
		}
};

int main() {
}
