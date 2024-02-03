#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
	vector<pair<int, int>> v;
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> res = {};
		for (auto interval: intervals) {
			v.push_back({interval[0], interval[1]});
		}
		sort(v.begin(), v.end());
		int f = v[0].first; 
		int s = v[1].second;
		for (int i = 0; i < v.size() - 1; i++) {
			if (s >= v[i + 1].first) {
				s = max(s, v[i + 1].second);
			} else {
				res.push_back({f, s});
				f = v[i + 1].first;
				s = v[i + 1].second;
			}
		}
		res.push_back({f, s});
		return res;
	}
};

int main() {
	return 0;
}
