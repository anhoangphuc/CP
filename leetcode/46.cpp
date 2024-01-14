#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<vector<int>> res;
            do {
                res.push_back(nums);
            } while (next_permutation(nums.begin(), nums.end()));
            return res;
        }
};

int main() {
    Solution a = Solution();
    vector<int> nums { 1, 1 };
    auto res = a.permute(nums);
    for (auto x: res) {
        for (auto y:x) {
            cout << y << " ";
        }
        cout << endl;
    }
}
