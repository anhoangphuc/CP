#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int reverse(int x) {
        string ax = to_string(x);
        reverse(ax.begin(), ax.end());
        cout << ax;
        return 3;
    }
};

int main() {
    Solution a = Solution();
    a.reverse(3);
}