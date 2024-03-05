#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.front() < nums.back())
            return nums.front();
        auto res = nums.front();
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j) {
            while (i + 1 <= j && nums[i] == nums[i + 1])
                i++;
            while (j - 1 >= i && nums[j] == nums[j - 1])
                j--;
            if (i > j)
                break;
            auto mid = (i + j) / 2;
            if (nums[mid] < nums.front()) {
                res = nums[mid];
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return res;
    }
};
