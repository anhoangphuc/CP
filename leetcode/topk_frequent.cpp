#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	map<int, int> m;
	vector<int> ds;
	vector<int> res;
	void quick_select(int l, int r, int top_select) {
		if (l > r) return;
		if (top_select == 0)
			return;

		int pivot = m[ds[(l + r) / 2]];
		int i = l, j = r;
		while (i <= j) {
			while (i < r && m[ds[i]] < pivot) i++;
			while (j >= 0 && m[ds[j]] > pivot) j--;
			if (i < j) {
				swap(ds[i], ds[j]);
				i++; j--;
			}
		}
		
		if (r - j == top_select) 
			res.insert(res.begin(), ds.begin() + r, ds.end());
		else if (r - j < top_select) {
			res.insert(res.begin(), )
		}
	}

	vector<int> topKFrequent(vector<int> nums, int k) {
		for (auto num: nums) {
			m[num] += 1;	
			if (m[num] == 1) 
				ds.push_back(num);
			
		}
	}	
}