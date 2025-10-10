#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> majorElement(vector<int>& nums) {
            int candidate1(0), candidate2(0), count1(0), count2(0);
            for (auto num: nums) {
                if (count1 != 0 && candidate1 == num) {
                    count1 += 1;
                } else if (count2 != 0 && candidate2 == num) {
                    count2 += 1;
                } else if (count1 == 0) {
                    count1 = 1;
                    candidate1 = num;
                } else if (count2 == 0) {
                    count2 = 1;
                    candidate2 = num;
                } else {
                    count1 -= 1;
                    count2 -= 1;
                }
            }
            vector<int> res = {};
            int n = ssize(nums);
            if (ranges::count(nums, candidate1) > n / 3) {
                res.push_back(candidate1);
            }
            if (candidate2 != candidate1 && ranges::count(nums, candidate2) > n / 3) {
                res.push_back(candidate2);
            }
            return res;
        }
};

int main() {
    Solution s = Solution();
    vector<int> v = { 2, 2, 1, 3 };
    s.majorElement(v);
}
