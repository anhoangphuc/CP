#include <vector>

using namespace std;


class Solution {
    public:
        int largestPerimeter(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            auto L = ssize(nums);
            int res = 0;
            for (auto i = 2; i < L; i++) {
                auto tmp = nums[i - 1] + nums[i - 2];
                if (tmp > nums[i]) {
                    res = max(res, nums[i] + tmp);
                }
            }
            return res;
        }
};

int main() {
    Solution s = Solution();
    vector<int> nums = { 2, 1, 2 };
    s.largestPerimeter(nums);
}
