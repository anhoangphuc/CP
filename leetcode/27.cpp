#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int removeElements(vector<int>& nums, int val) {
			int kInd = 0;
			for (int i = 0; i < nums.size(); i++) {
				while (kInd < nums.size() && nums[kInd] == val) {
					kInd++;
				}
				if (kInd == nums.size()) {
					return i;
				}
				nums[i] = nums[kInd++];
			}
			return nums.size();
		}
};

int main() {
	Solution a = Solution();
	vector<int> x = {0,1,2,2,3,0,4,2};
	int k = a.removeElements(x, 2);
	cout << "k " << k << endl;
	for (auto y: x) {
		cout << y << " ";
	}
}
