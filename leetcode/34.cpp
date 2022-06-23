#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> searchRanges(vector<int>& nums, int target) {
            auto first = lower_bound(nums.begin(), nums.end(), target);
            auto last = upper_bound(nums.begin(), nums.end(), target);
            auto firstIndex = first - nums.begin();
            auto lastIndex = last - nums.begin() - 1;
            vector<int> res;
            res.push_back(firstIndex > lastIndex ? -1 : firstIndex);
            res.push_back(firstIndex > lastIndex ? -1 : lastIndex);
            return res;
        }
};

int main() {
    Solution x = Solution();
    vector<int> v { 1, 2, 3 };
    auto res = x.searchRanges(v, 2);
    for (auto x: res)
        cout << x << " ";
}
