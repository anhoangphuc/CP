#include <iostream>	
#include <vector>
using namespace std;

class Solution {
	public:
		int removeDuplicates(vector<int>& nums) {
			int currentIndex = 0;
			for (int i = 0; i < nums.size(); i++) {
				if (currentIndex >= 2 && nums[i] == nums[currentIndex - 1] && nums[i] == nums[currentIndex - 2]) {
					continue;
				}
				nums[currentIndex++] = nums[i];				
			}
			return currentIndex;
		}
};

int main() {
	Solution a = Solution();
	vector<int> x = {1, 1, 1, 2, 2, 3};
	int k = a.removeDuplicates(x);
	cout << "k " << k << endl;
	for (auto y:x) {
		cout << y << " ";
	}
	
}

