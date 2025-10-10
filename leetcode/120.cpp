#include <vector>
#include <iostream>

//using vvi = vector<vector<int>>;

using namespace std;


class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            vector<vector<int>> result;
            result.push_back({ triangle[0][0] });

            auto L = ssize(triangle);
            if (L == 1) {
                return triangle[0][0];
            }
            for (auto i = 1; i < L; i++) {
                // n is the length in height i
                auto n = i + 1;
                result.push_back({});
                for (auto j = 0; j < n; j++) {
                    auto tmp = triangle[i][j];
                    if (j == 0) {
                        tmp += result[i - 1][j];
                    } else if (j == n - 1) {
                        tmp += result[i - 1][j - 1];
                    } else {
                        tmp += min(result[i - 1][j], result[i - 1][j - 1]);
                    }
                    result[i].push_back(tmp);
                }
            }
            int res = *min_element(result.back().begin(), result.back().end());
            return res;
        }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> v = {{2},{3,4},{6,5,7},{4,1,8,3}};
    auto res = s.minimumTotal(v);
    cout << res;
}
