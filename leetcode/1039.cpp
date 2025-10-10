#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
    public:
        int minScoreTriangulation(vi& values) {
            auto n = ssize(values);
            vvi d(n, vector<int>(n));
            return getValue(d, values, 0, n - 1);
        }

        int getValue(vvi& d, vi& values, int i, int j) {
            if (i + 2 > j) {
                return 0;
            }
            if (i + 2 == j) {
                return values[i] * values[i + 1] * values[i + 2];
            }
            if (d[i][j] != 0) {
                return d[i][j];
            }
            int tmp = 1e9 + 7;
            for (auto k = i + 1; k < j; k++) {
                tmp = min(tmp, getValue(d, values, i, k) + getValue(d, values, k, j) + values[i] * values[j] * values[k]);
            }

            d[i][j] = tmp;
            return tmp;
        }
};

int main() {
    Solution s = Solution();
    vector<int> v = { 1, 3, 1, 4, 1, 5 };
    auto res = s.minScoreTriangulation(v);
    cout << res << endl;
}
