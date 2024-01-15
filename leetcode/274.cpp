#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
	int hIndex(vector<int>& citations) {
		sort(citations.begin(), citations.end());
		int j = 0;
		int res = 0;
		for (int i = 0; i < 1000; i++) {
			while (j < citations.size() && citations[j] < i) j++;
			if (citations.size() - j >= i) {
				res = i;	
			} else break;
		}
		return res;
	}
};

int main() {
	Solution a = Solution();
	vector<int> citations {1, 3, 1};
	int hIndex = a.hIndex(citations);
	cout << hIndex ;
}
