#include <vector>

using namespace std;


class Solution {
    public:
        long long minTime(vector<int>& skill, vector<int>& mana) {
            int m = ssize(skill);
            int n = ssize(mana);

            vector<long long> d(m + 1);
            vector<long long> r(m + 1);
            for (auto j = 0; j < n; j++) {
                // Accumulate
                for (auto i = 1; i <= m; i++) {
                    d[i] = d[i - 1] + skill[i - 1] * mana[j];
                }
                
                // if j == 0, assign r as j
                if (j == 0) {
                    for (auto i = 1; i <= m; i++) {
                        r[i] = d[i];
                    }
                    continue;
                }
                
                // else if j <> 0
                long long tmp = 0;
                for (auto i = 1; i <= m; i++) {
                    tmp = max(tmp, r[i] - d[i - 1]);
                }

                for (auto i = 1; i <= m; i++) {
                    r[i] = tmp + d[i];
                }
            }

            return r[m];
        }
};

int main() {
    Solution s = Solution();
}
