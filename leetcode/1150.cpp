#include <vector>

using namespace std;


class Solution {
    public:
        bool isMajorityElement(vector<int>& nums, int target) {
            auto lowerBound = lower_bound(nums.begin(), nums.end(), target);
            auto upperBound = upper_bound(nums.begin(), nums.end(), target);

            if (nums.front() > target) {
                return false;
            }
            if (nums.back() < target) {
                return false;
            }
            return (upperBound - lowerBound) > ssize(nums) / 2;
        }
};

int main() {

}
