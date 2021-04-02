#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& a) {
		int res = 0, cur = 0;
		bool buyed = false;

		a.push_back(0);
		for (int i = 0; i < a.size(); i++) {
			if (a[i] < a[i + 1] && !buyed) {
				buyed = true;
				cur = a[i];
			} else if (a[i] > a[i + 1] && buyed) {
				buyed = false;
				res += a[i] - cur;
			}
		}
		return res;
	}
};

int main() {
	Solution a = Solution();
	vector<int> b {7, 1, 5, 3, 6, 4};
	cout << a.maxProfit(b);
};
