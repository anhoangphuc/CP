#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstringTwoDistinct(string s) {
            map<char, int> d;
            int res = 1;
            int j = 0;
            d[s[0]] = 1;
            auto L = ssize(s);
            int cnt = 1;
            for (auto i = 1; i < L; i++) {
                auto ch = s[i];

                // If d[ch] == 1, new character added
                d[ch] += 1;
                cnt += (d[ch] == 1);
                while (cnt > 2) {
                    // If d[s[j]] == 0, new character removed
                    d[s[j]] -= 1;
                    cnt -= (d[s[j]] == 0);
                    j += 1;
                }
                res = max(res, i - j + 1);
            }

            return res;
        }
};

int main() {
    Solution solution = Solution();
    string s = "ccaabbb";
    auto res = solution.lengthOfLongestSubstringTwoDistinct(s);
    cout << res << endl;
}
