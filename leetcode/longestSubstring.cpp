#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			map<char, int> m;
			int res = 0;
			int pPosition = -1;
			for (int i = 0; i < s.length(); i++) {
				if (m.find(s[i]) != m.end())
					pPosition = max(pPosition, m[s[i]]);
				m[s[i]] = i;
				//cout << i << " " << pPosition << endl;
				res = max(res, i - pPosition);
			}	
			return res;
		}
};

int main() {
	Solution a = Solution();
	cout << a.lengthOfLongestSubstring(" ");
}
