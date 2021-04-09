#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    static const int NMAX = 3e4 + 3;
    vector<int> ds[2 * NMAX];
    int t[2 * NMAX];
    int pos[2 * NMAX];
    int longestValidParentheses(string s) {
        memset(pos, 0, sizeof(pos));
        memset(t, 0, sizeof(t));
        for (auto i = 0; i < 2 * NMAX; i++)
            ds[i].clear();

        for (int i = 0; i < s.size(); i++) {
            int g = (i == 0 ? NMAX : t[i - 1]);
            t[i] = g + (s[i] == '(' ? 1 : -1);
        }
        
    }
};