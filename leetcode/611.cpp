#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        int triangleNumber(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            auto L = ssize(nums);
            if (L < 3) {
                return 0;
            }
            int res = 0;
            for (auto i = 1; i < L - 1; i++) {
                for (auto j = 0; j < i; j++) {
                    //if (nums[i] || nums[j] == 0) continue;
                    auto v = nums[i] + nums[j];
                    //cout << j << " " << i << " " << nums[j] << " " << nums[i] << " " << v << " ";
                    auto t = lower_bound(nums.begin() + i + 1, nums.end(), v);
                    res += (t - nums.begin() - i - 1);
                }
            }
            return res;
        }
};  

int main() {
    Solution s = Solution();
    vector<int> nums = { 2, 2, 3, 4 };
    auto res = s.triangleNumber(nums);
    cout << res;
}
