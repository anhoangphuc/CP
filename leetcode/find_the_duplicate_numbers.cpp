#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b, step) for (auto i = a; i < b; i += step)
#define repr(i, a, b, step) for (auto i = a; i > b; i -= step)

typedef pair<int, int> pii;

class Solution {
    public:
    int findDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == -1) 
                continue;
            int org = i, j = i;
            while (nums[j] > 0) {
                int tg = nums[j] - 1;
                nums[j] = -1;
                j = tg;
            }
            if (j != org) {
                return j + 1;
            }
        } 
        return -1;
    }
};
int main() {
    Solution a = Solution();
    vector<int> v{1, 3, 3, 4};
    int res = a.findDuplicate(v);
    cout << res;
}
