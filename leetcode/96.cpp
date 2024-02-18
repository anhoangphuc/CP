#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
	int numTrees(int n) {
		vector<int> dp(n + 1);
		dp[0] = 1;
		for (auto numberOfNodes = 1; numberOfNodes <= n; numberOfNodes++) {
			for (int i = 1; i <= numberOfNodes; i++) {
				int j = numberOfNodes - i;
				dp[numberOfNodes] += dp[i - 1] * dp[j];
			}
		}
		return dp[n];
	}
};

int main() {
	return 0;
}
