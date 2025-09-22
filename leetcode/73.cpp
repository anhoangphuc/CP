#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            auto m = ssize(matrix);
            auto n = ssize(matrix[0]);
            bool r0 = false, c0 = false;
            for (auto i = 0; i < m; i++) {
                if (matrix[i][0] == 0) {
                    c0 = true;
                    break;
                }
            }

            for (auto j = 0; j < n; j++) {
                if (matrix[0][j] == 0) {
                    r0 = true;
                    break;
                }
            }

            for (auto i = 1; i < m; i++) {
                for (auto j = 0; j < n; j++) {
                    if (matrix[i][j] == 0) {
                        matrix[i][0] = 0;
                        break;
                    }
                }
            }

            for (auto j = 1; j < n; j++) {
                for (auto i = 0; i < m; i++) {
                    if (matrix[i][j] == 0) {
                        matrix[0][j] = 0;
                    }
                }
            }

            for (auto i = 1; i < m; i++) {
                if (matrix[i][0] != 0) continue;
                for (auto j = 0; j < n; j++)
                    matrix[i][j] = 0;
            }

            for (auto j = 1; j < n; j++) {
                if (matrix[0][j] != 0) continue;
                for (auto i = 0; i < m; i++) {
                    matrix[i][j] = 0;
                }
            }

            if (r0) {
                for (auto j = 0; j < n; j++) {
                    matrix[0][j] = 0;
                }
            }

            if (c0) {
                for (auto i = 0; i < m; i++) {
                    matrix[i][0] = 0;
                }
            }
        }
};

int main() {
    auto s = Solution();
    vector<vector<int>> v = { {0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5} };
    s.setZeroes(v);
    for (auto v1: v) {
        for (auto v2: v1) {
            cout << v2 << " ";
        }
        cout << endl;
    }
}
