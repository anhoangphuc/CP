#include <bits/stdc++.h>
using namespace std;


class Solution {
	public: 
		bool f[1002][1002];
		string longestPalindrome(string s) {
			for (int i = 0; i < s.length(); i++) {
				f[i][i] = 1;
				f[i + 1][i] = 1;
			}

			int res = 0;
			string rres = "";
			if (s.length() > 0) {
				res = 0;
				rres = s[0];
			}
			for (int l = 2; l <= s.length(); l++) 
				for (int i = 0; i < s.length(); i++) {
					int j = i + l - 1;
					if (j >= s.length()) continue;
					if (f[i + 1][j - 1] == 0 || s[i] != s[j]) continue;
					f[i][j] = 1;
					if (j - i + 1 > res) {
						res = j - i + 1;
						rres = s.substr(i, j - i + 1);
					}
				} 
			return rres;
		}
};

int main() {
	Solution a = Solution();
	cout << a.longestPalindrome("cbefeb");
}
