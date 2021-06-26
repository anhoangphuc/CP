#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, res = 0; 
        for (char chr: s) {
            if (chr == '(') 
                left += 1;
            else
                right += 1;
            if (left == right) 
                res = max(res, left * 2);
            if (left < right) {
                left = 0;
                right = 0;
            }
        }

        left = 0; right = 0;
        for (char chr: string(s.rbegin(), s.rend())) {
            if (chr == '(')
                left += 1;
            else
                right += 1;
            if (left == right)
                res = max(res, left * 2);
            if (left > right) {
                left = 0;
                right = 0;
            }
        }
        return res;
    }
};

int main() {
    Solution a = Solution();
    cout << a.longestValidParentheses("(()");
    cout << a.longestValidParentheses("(())");
}