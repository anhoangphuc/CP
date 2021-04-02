#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string convert(string s, int numRows) {
			if (numRows == 1) return s;
			typedef pair<pair<int, int>, char> t;	
			vector<t> g;
			int x[2] = {1, -1}, y[2] = {0, 1};
			int u(-1), v(0), dir(0);
			for (int i = 0; i <	s.length(); i++) {
				u += x[dir]; v += y[dir];
				//cout << u << " " << v << " " << i << " " << s[i] << endl;
				g.push_back(make_pair(make_pair(u, v), s[i]));
				if (i > 0 && (i % (numRows - 1)) == 0)
					dir = dir ^ 1;
			}
			sort(g.begin(), g.end());
			string res = "";
			for (auto x: g) 
				res += x.second;
			return res;
		}
};

int main() {
	Solution a = Solution();
	cout << a.convert("PAYPALISHIRING", 3);
}
