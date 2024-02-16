#include <vector>
#include <set>

using namespace std;

class Solution {
	public:
	set<pair<int, pair<int, int>>> s;	
	vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		for (int i = 0; i< nums1.size(); i++) {
			s.insert({nums1[i] + nums2[0], {i, 0}});
		}				
		vector<vector<int>> res = {};
		while (k > 0) {
			auto t = *s.begin();						
			auto iIndex = t.second.first;
			auto jIndex = t.second.second;
			res.push_back({nums1[iIndex], nums2[jIndex]});
			s.erase(s.begin());
			if (jIndex + 1 < nums2.size()) {
				s.insert({nums1[iIndex] + nums2[jIndex + 1], {iIndex, jIndex + 1}});
			}
			k--;
		}
		return res;
	}
};

int main() {
	return 0;
}
