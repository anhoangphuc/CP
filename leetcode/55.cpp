#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b, step) for (auto i = a; i < b; i += step)
#define repr(i, a, b, step) for (auto i = a; i > b; i -= step)

typedef pair<int, int> pii;

class Solution {
    public:
    bool canJump(vector<int>& nums) {
        int maxJump = 0;
        rep(i, 0, nums.size(), 1) {
            if (i > maxJump)
                break;
            maxJump = max(maxJump, i + nums[i]);
        }
        return (maxJump >= nums.size() - 1);
    }
};

int main() {
    Solution a = Solution();
    vector<int> x = { 2, 3, 1, 1, 4 };
    cout << a.canJump(x);
}