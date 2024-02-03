class Solution {
public:
    unordered_map<int, int> mp;
    int longestConsecutive(vector<int>& nums) {
        for (auto num : nums) {
            mp[num] = -1;
        }
        int res(0);
        for (auto num : nums) {
            // Not yet try
            if (mp[num] == -1) {
                res = max(res, tryValue(num));
            }
        }
        return res;
    }

    int tryValue(int k) {
        if (mp.find(k - 1) == mp.end()) {
            mp[k] = 1;
            return mp[k];
        }
        // Already try
        if (mp[k - 1] != -1) {
            mp[k] = 1 + mp[k - 1];
            return mp[k];
        }
        mp[k] = 1 + tryValue(k - 1);
        return mp[k];
    }
};
