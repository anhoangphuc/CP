#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 1; i >= 0; i--) { 
            int ma = 101, k = -1;
            for (int j = i + 1; j < nums.size(); j++) 
                if (nums[j] > nums[i] && nums[j] < ma) {
                    ma = nums[j];
                    k = j;
                }
            if (k != -1) {
                swap(nums[i], nums[k]);
                sort(nums.begin() + i + 1, nums.end());
                return; 
            }
        }
        sort(nums.begin(), nums.end());
    }
};

int main() {
    Solution a = Solution();
    vector<int> nums = {3, 2, 1};
    a.nextPermutation(nums);
    for (int num:nums) 
        cout << num;
}