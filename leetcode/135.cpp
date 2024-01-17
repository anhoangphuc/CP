#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
	int candy(vector<int>& ratings) {
		int len = ratings.size();
		vector<int> left(len);
		vector<int> right(len);
		for (int i = 0; i < len; i++) {
			if (i == 0 || ratings[i] <= ratings[i - 1]) {
				left[i] = 1;
			} else {
				left[i] = left[i - 1] + 1;
			}
		}

		for (int i = len - 1; i >= 0; i--) {
			if (i == len - 1 || ratings[i] <= ratings[i + 1]) {
				right[i] = 1;
			} else {
				right[i] = right[i + 1] + 1;
			}
		}

		int res = 0;
		for (int i = 0; i < len; i++) {
			res += max(left[i], right[i]);
		}	
		return res;
	}
};

int main() {
	Solution a = Solution();
	vector<int> ratings {1, 2, 2};
	int res = a.candy(ratings);
	cout << res;
}

