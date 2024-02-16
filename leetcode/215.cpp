#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct cmp {
	bool operator () (int val1, int val2) const {
		return val1 > val2;
	}
};
class Solution {
	public:
	int findKthLargest(vector<int>& nums, int k) {
		multiset<int, cmp> s;
		for (auto num: nums) {
			s.insert(num);
		}

		int cnt(0);
		while (!s.empty()) {
			cnt += 1;
			int val = *s.begin();
			if (cnt == k) return val;
			s.erase(s.begin());
		}

		return 0;
	}
};

int main() {
	return 0;
}
