#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        //vector<vector<bool>> match { vector<vector<bool>>(2001, vector<bool>(2001, false)) };
        bool match[2001][2001];
        bool isMatch(string s, string p) {
            match[0][0] = true;
            if (p[0] == '*') match[1][0] = true;
            for (int i = 0; i < p.length(); i++) {
                if (p[i] == '*') match[i + 1][0] = true;
                else break;
            }
            for (int i = 0; i < p.length(); i++) {
                for (int j = 0; j < s.length(); j++) {
                    if (p[i] == s[j] && match[i][j]) match[i + 1][j + 1] = true;
                    if (p[i] == '?' && match[i][j]) match[i + 1][j + 1] = true;
                    if (p[i] == '*') {
                        if (match[i][j] || match[i + 1][j] || match[i][j + 1]) match[i + 1][j + 1] = true;
                    }
                }
            }

            return match[p.length()][s.length()];
        }
};


int main() {
    Solution a = Solution();
    cout << a.isMatch("acbcccab", "**a*");
}
//m??*ss*? i*pi
//m ississippi
