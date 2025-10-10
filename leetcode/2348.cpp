#include <vector>

using namespace std;


class Solution {
    public:
        long long zeroFilledSubarray(vector<int>& nums) {
            long long res = 0;        
            long long d = 0;
            nums.push_back(1);
            for (auto num: nums) {
                if (num == 0) {
                    d += 1;
                } else {
                    res += d * (d + 1) / 2;
                    d = 0;
                }
            }
            return res;
        }
};
