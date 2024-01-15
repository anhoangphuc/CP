#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 1) return 0;		
		int minValue(prices[0]), res(0);
		for (auto price: prices) {
			res = max(res, price - minValue);
			minValue = min(minValue, price);
		}

		return res;
	}
};

int main() {
	Solution a = Solution();
	vector<int> prices {7, 6, 5, 4, 3, 2, 1};
	int res = a.maxProfit(prices);
	cout << res;
}
