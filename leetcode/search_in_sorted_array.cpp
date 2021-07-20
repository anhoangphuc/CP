#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, index = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid > 0 && nums[mid] < nums[mid - 1]) {
                index = mid;
                break;
            }
            else if (nums[mid] > nums[r])
                l = mid + 1;
            else 
                r = mid - 1;
        }
        cout << "index " << index << endl;

        if (index > 0 && nums[index - 1] >= target) {
            auto it = lower_bound(nums.begin(), nums.begin() + index, target);
            if (*it == target) 
                return (it - nums.begin());
        }
        if (nums[nums.size() - 1] >= target) {
            auto it = lower_bound(nums.begin() + index, nums.end(), target);
            if (*it == target)
                return (it - nums.begin());
        }
        return -1;
    }    
};

int main() {
    Solution a = Solution();
    vector<int> v = {3, 1};
    auto x = a.search(v, 1);
    cout << x;
}