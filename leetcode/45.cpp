#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        int jump(vector<int>& nums) {
            vector<int> f(nums.size() + 1, INT_MAX);
            f[0] = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (f[i] == INT_MAX) continue;
                for (int j = 1; j <= nums[i]; j++) {
                    if (i + j >= nums.size()) continue;
                    f[i + j] = min(f[i + j], f[i] + 1);
                }
            }

            return f[nums.size() - 1];
        }
};

int main() {
    Solution a = Solution();
    vector<int> nums { 2, 3, 1, 1, 4 };
    int res = a.jump(nums);
    cout << res;
}
