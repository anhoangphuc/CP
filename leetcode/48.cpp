#include <vector>
#include <iostream>

using namespace std;

class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int x = matrix.size() - 1;
            vector<pair<int, int>> v(4);
            for (int i = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix.size(); j++) {
                    v[0] = { i, j };
                    v[1] = { j, x - i };
                    v[2] = { x - i, x - j };
                    v[3] = { x - j, i };
                    if (v[0] > v[1] || v[0] > v[2] || v[0] > v[3]) continue;
                    swap(matrix[v[0].first][v[0].second], matrix[v[1].first][v[1].second]);
                    swap(matrix[v[0].first][v[0].second], matrix[v[2].first][v[2].second]);
                    swap(matrix[v[0].first][v[0].second], matrix[v[3].first][v[3].second]);
                }
            }
        }
};

int main() {
    Solution a = Solution();
    vector<vector<int>> matrix {{ 1 }};
    a.rotate(matrix);
}
