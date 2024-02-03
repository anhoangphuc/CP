class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = 100001;
        int curSum = 0;
        int j = 0;
        int previousSum = 0;
        int k(100001);
        for (int i = 0; i < nums.size(); i++) {
            if (curSum + nums[i] < target) {
                curSum += nums[i];
            } else {
                k = i;
                break;
            }
        }
        for (int i = k; i < nums.size(); i++) {
            curSum += nums[i];
            while (curSum - previousSum - nums[j] >= target) {
                previousSum += nums[j];
                j += 1;
            }
            res = min(res, i - j + 1);
        }
        if (res == 100001) return 0;
        else return res;
    }
};
