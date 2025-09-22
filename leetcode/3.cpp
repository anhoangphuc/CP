#include <string>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }

        map<char, int> d;
        int left = 0;
        int res = 1;
        d[s[0]] = 1;
        for (int i = 1; i < ssize(s); i++) {
            char x = s[i];
            d[x] = d[x] + 1;
            if (d[x] == 1) {
                res = max(res, i - left + 1);
            } else {
                while (d[x] == 2) {
                    d[s[left]] -= 1;
                    left += 1;
                }
            }
        }

        return res;
	}
};

int main() {
    Solution a = Solution();
    auto s = "aaaaa";
    auto res = a.lengthOfLongestSubstring(s);
    cout << res;
}
