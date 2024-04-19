#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Solution {
	public:
		bool isInterleave(string s1, string s2, string s3) {
			if (s1.size() + s2.size() != s3.size()) return false;
			vector<vector<bool>> d(101, vector<bool>(101));		
			d[0][0] = true;
			for (int i = 0; i <= s1.size(); i++) {
				for (int j = 0; j <= s2.size(); j++) {
					if (d[i][j]) {
						if (i < s1.size() && s1[i] == s3[i + j]) d[i + 1][j] = true;
						if (j < s2.size() && s2[j] == s3[i + j]) d[i][j + 1] = true;
					}
				}
			}
			return d[s1.size()][s2.size()];
		}
};

int main() {
	Solution a = Solution();
	cout << a.isInterleave("tt", "ta", "tata");
}
