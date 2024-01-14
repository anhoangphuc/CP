#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
    public:
        vector<vector<int>> res;
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());
            int x1 = INT_MIN, x2 = INT_MIN, x3 = INT_MIN, x4 = INT_MIN;
            for (int i = 0; i < nums.size(); i++) {
                for (int j = i + 1; j < nums.size(); j++) {
                    int t = nums.size() - 1;
                    for (int k = j + 1; k < nums.size(); k++) {
                        // remove value from k-th positions

                        // found value
                        long long int currentSum = nums[i] + nums[j] + nums[k];
                        long long int findValue = target - currentSum;
                        while (t > k && nums[t] > findValue) t--;
                        if (t > k && nums[t] == findValue) {
                            if (res.size() == 0 || cmp(x1, x2, x3, x4, nums[i], nums[j], nums[k], findValue)) {
                                res.push_back({ nums[i], nums[j], nums[k], (int)findValue });
                                x1 = nums[i];
                                x2 = nums[j];
                                x3 = nums[k];
                                x4 = findValue;
                            }
                        }
                    }
                }
            }
            return res;
        }
    private:
        bool cmp(int x1, int x2, int x3, int x4, int y1, int y2, int y3, long long int y4) {
            if (x1 != y1) return (x1 < y1);
            if (x2 != y2) return (x2 < y2);
            if (x3 != y3) return (x3 < y3);
            return (x4 < y4);
        }
};

int main() {
    Solution a = Solution();
    vector<int> nums {-5,-4,-3,-2,-1,0,0,1,2,3,4,5};
    auto res = a.fourSum(nums, 0);
    for (auto g: res) {
        for (auto x: g) {
            cout << x << " ";
        }
        cout << endl;
    }
}
