#include <iostream>
#include <vector>

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;

class Solution {
    public:
        vvi generateMatrix(int n) {
            vvi res = {};
            for (auto i = 0; i < n; i++) {
                vector<int> v(n);
                res.push_back(v);
            }

            vi px = { 0, 1, 0, -1 };
            vi py = { 1, 0, -1, 0 };
            auto direction = 0;
            int x = 0;
            int y = 0;
            for (auto i = 1; i <= n * n; i++) {
                //cout << x <<  " " << y <<  " " << i << endl;
                res[x][y] = i;
                auto nx = x + px[direction];
                auto ny = y + py[direction];
                if ((nx >= 0 && nx < n && ny >= 0 && ny < n) && (res[nx][ny] == 0)) {
                    x = nx;
                    y = ny;
                } else {
                    direction = (direction + 1) % 4;
                    x = x + px[direction];
                    y = y + py[direction];
                }
            }
            return res;
        }
};

int main() {
    Solution s = Solution();
    auto res = s.generateMatrix(3);
    for (auto x: res) {
        for (auto y: x) {
            cout << y <<  " ";
        }
        cout << endl;
    }
}
