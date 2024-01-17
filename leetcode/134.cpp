#include <vector>
#include <iostream>

using namespace std;

class Solution {
	public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int len = gas.size();
		vector<int> minLeft(len);
		vector<int> minRight(len);
		for (int i = 0; i < len; i++) {
			gas[i] = gas[i] - cost[i];
			if (i > 0) {
				gas[i] = gas[i - 1] + gas[i];	
				minLeft[i] = min(minLeft[i - 1], gas[i]);
			} else {
				minLeft[i] = gas[i];
			}
		}		
		for (int i = len - 1; i >= 0; i--) {
			if (i == gas.size() - 1) {
				minRight[i] = gas[i];
			} else {
				minRight[i] = min(minRight[i + 1], gas[i]);
			}
		}
		for (int i = 0; i < len; i++) {
			if (i == 0) {
				if (minLeft[len - 1] >= 0) {
					return i;
				}
			} else {
				int value1 = minRight[i] - gas[i - 1];
				int value2 = (gas[len - 1] - gas[i - 1]) + minLeft[i - 1];
				if (value1 >= 0 && value2 >= 0) {
					return i;
				}
			}
		}
		return -1;
	}
};

int main() {
	Solution a = Solution();
	vector<int> gas {5, 1, 2, 3, 4};
	vector<int> cost {4, 4, 1, 5, 1};
	int res = a.canCompleteCircuit(gas, cost);
	cout << res;
}

