#include <vector>
using namespace std;

class Solution {
	public:
		void sortColors(vector<int>& nums) {
			        int i = 0;
        int j = nums.size() - 1;
        int cur = 0;
        while (cur <= j) {
            if (nums[cur] == 0) {
                swap(nums[i], nums[cur]);
                i++;
                cur++;
            } else if (nums[cur] == 2) {
                swap(nums[cur], nums[j]);
                j -= 1;
            } else {
                cur += 1;
            }
        }
		}
};
