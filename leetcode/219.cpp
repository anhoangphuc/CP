class Solution {
public:
    map<int, int> mp;
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for (auto i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end()) {
                int j = mp[nums[i]];
                if (i - j <= k)
                    return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};
