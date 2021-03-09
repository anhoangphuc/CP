#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			int totalSize = nums1.size() + nums2.size();
			bool ok = false;
			//int v = findMedian(nums2, nums1, (totalSize + 1)/ 2, ok);
			//cout << v << endl;
			//return 0;
			int u = findMedian(nums1, nums2, totalSize / 2 + 1, ok);
			cout << "1u " << u << endl;
			if (!ok) 
				u = findMedian(nums2, nums1, totalSize / 2 + 1, ok);
			cout << "2u " << u << endl;
			ok = false;
			int v = findMedian(nums1, nums2, (totalSize + 1)/ 2, ok);
			cout << "1v " << v << endl;
			if (!ok) 
				v = findMedian(nums2, nums1, (totalSize + 1)/ 2, ok);
			cout << "2v " << v << endl;
			cout << u << " " << v << endl;
			return (u + v * 1.0) / 2;
		}
	private:
		int findMedian(vector<int>& nums1, vector<int>& nums2, int k, bool& ok) {
			cout << "k: " << k << endl;
			ok = false;	
			if (nums1.size() == 0) {
				return 0;
			}
			int l = 0, r = nums1.size() - 1;
			while (l <= r) {
				cout << l << " " << r << endl;
				int mid = (l + r) / 2;
				cout << "nums1 mid " << nums1[mid] << endl;
				auto pa = equal_range(nums2.begin(), nums2.end(), nums1[mid]);
				if (pa.first != nums2.end()) {
					cout << "equal " << endl;
					int u1 = static_cast<int> (pa.first - nums2.begin());
					int u2;
					if (pa.second != nums2.end())
					u2 = static_cast<int> (pa.second - nums2.begin());
					else u2 = nums2.size();
					if (mid + u1 <= k - 1 && mid + u2 >= k - 1) {
						ok = true;
						return nums1[mid];
					} 
					else if (mid + u1 > k - 1)
						r = mid - 1;
					else 
						l = mid + 1;
				} else
				{
					cout << "not equal " << endl;
				int pos;
				auto ind = upper_bound(nums2.begin(), nums2.end(), nums1[mid]);
				if (ind == nums2.end()) 
					pos = nums2.size();
				else 
					pos = static_cast<int>(ind - nums2.begin());
				cout << mid << " " << pos << endl;
				if (mid + pos == k - 1) {
					ok = true;
					return nums1[mid];
				}
				else if (mid + pos > k - 1)
					r = mid - 1;
				else 
					l = mid + 1;

				}
			}
			return 0;
		}
};

int main() {
	Solution a = Solution();
	vector<int> nums1 {1, 4};
	vector<int> nums2 {2, 3};
	cout << a.findMedianSortedArrays(nums1, nums2);
}
