#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
	int maxProfit(vector<int>& prices) {
		int res(0), curValue(100001);

		for (auto price: prices) {
			if (price > curValue) {
				res += (price - curValue);
			} 
			curValue = price;
		}

		return res;
	}
};

int main() {
	Solution a = Solution();
	vector<int> prices {1, 2, 3, 4, 5};
	int res = a.maxProfit(prices);
	cout << res;
}
