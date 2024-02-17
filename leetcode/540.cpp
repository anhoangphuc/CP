#include <vector>
using namespace std;

class Solution {
	public:
    int singleNonDuplicate(vector<int>& nums) {
        return xorHelper(nums, 0, nums.size() - 1);
    }
    int xorHelper(vector<int>& nums, int l, int r) {
        if (l == r)
            return nums[l];
        int mid = (l + r) / 2;
        int leftResult = xorHelper(nums, l, mid);
        int rightResult = xorHelper(nums, mid + 1, r);
        return leftResult ^ rightResult;
    }
};

int main() {
	return 0;
}
