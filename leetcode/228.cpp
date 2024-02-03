class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res = {};
        if (nums.size() == 0)
            return res;
        int low = nums[0];
        int high = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                high = nums[i];
            } else {
                if (low == high)
                    res.push_back(to_string(low));
                else
                    res.push_back(to_string(low) + "->" + to_string(high));
                low = nums[i];
                high = nums[i];
            }
        }
        if (low == high)
            res.push_back(to_string(low));
        else
            res.push_back(to_string(low) + "->" + to_string(high));

        return res;
    }
};
