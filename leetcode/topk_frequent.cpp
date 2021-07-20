#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	map<int, int> m;
	vector<int> ds;
	vector<int> res;
	void quick_select(int l, int r, int top_select) {
		if (l >= r) return;
		if (top_select == 0)
			return;
		if (l + 1 == r) {
			res.push_back(ds[l]);
			return;
		}
		int i = l, j = r - 1;
		int pivot = m[ds[(l + r) / 2]];
		while (i <= j) {
			while (i < r && m[ds[i]] > pivot) i++;
			while (j >= l && m[ds[j]] < pivot) j--;
			if (i <= j) {
				swap(ds[i], ds[j]);
				i++; j--;
			}
		}
		if (j - l + 1 == top_select) {
			res.insert(res.begin(), ds.begin() + l, ds.begin() + j + 1);
		} else if (top_select > j - l + 1) {
			res.insert(res.begin(), ds.begin() + l, ds.begin() + j + 1);
			quick_select(j + 1, r, top_select - (j - l + 1));
		} else {
			quick_select(l, j + 1, top_select);
		} 
	}

	vector<int> topKFrequent(vector<int> nums, int k) {
		for (auto num: nums) {
			m[num] += 1;	
			if (m[num] == 1) 
				ds.push_back(num);
		}
		quick_select(0, ds.size(), k);
		return res;
	}
};


int main() {
	Solution a = Solution();
	vector<int> v = {1};
	auto r = a.topKFrequent(v, 1);
	for (auto x: r) 
		cout << x << " ";
}