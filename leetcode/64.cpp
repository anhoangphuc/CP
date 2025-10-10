#include <vector>
#include <iostream>

using namespace std;

using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            auto m = ssize(grid);
            auto n = ssize(grid[0]);
            vvi res(m);
            for (auto i = 0; i < m; i++) {
                vi v(n);
                res[i] = v;
            }

            for (auto i = 0; i < m; i++) {
                for (auto j = 0; j < n; j++) {
                    int tmp = 1e9;
                    if (i > 0) tmp = res[i - 1][j];
                    if (j > 0) tmp = min(tmp, res[i][j - 1]);
                    res[i][j] = tmp == 1e9 ? grid[i][j] : grid[i][j] + tmp;
                }
            }
            return grid[m - 1][n - 1];
        }
};

int main() {

}
