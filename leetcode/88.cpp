#include <vector>
#include <iostream>
using namespace std;

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int i = m - 1;
		int j = n - 1;
		int k = m + n - 1;
		while (k >= 0) {
			if (i < 0) {
				nums1[k--] = nums2[j--];
			} else if (j < 0) {
				nums1[k--] = nums1[i--];
			} else if (nums1[i] >= nums2[j]) {
				nums1[k--] = nums1[i--];
			} else {
				nums1[k--] = nums2[j--];
			}
		}
        }
};

int main() {
	Solution a = Solution();	
	vector<int> num1 = {1, 2, 4, 5, 6, 0};
	vector<int> num2 = { 3};
	a.merge(num1, 5, num2, 1);
	for (auto x: num1) {
		cout << x << " ";
	}
}
