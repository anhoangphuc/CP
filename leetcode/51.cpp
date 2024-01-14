#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    public:
        const int NMAX = 10;
        vector<bool> c{vector<bool>(NMAX, false)}, dp{vector<bool>(2 * NMAX, false)}, dm{vector<bool>(2 * NMAX, false)};
        vector<vector<string>> res;
        vector<vector<string>> solveNQueens(int n) {
            vector<int> pos { vector<int>(n, -1) };
            tryPos(0, n, pos);
            for (auto x: res) {
                for (auto y: x) {
                    cout << y << " ";
                }

                cout << endl;
            }
            return res;
        }

    private:
        void tryPos(int row, int size, vector<int>& pos) {
            if (row == size) {
                vector<string> g;
                for (auto x: pos) {
                    string tmp { string(size, '.') };
                    tmp[x] = 'Q';
                    g.push_back(tmp);
                }
                res.push_back(g);
                return;
            }
            for (int i = 0; i < size; i++) {
                if (c[i] || dp[row + i] || dm[row - i + size]) continue;
                pos[row] = i;
                c[i] = true;
                dp[row + i] = true;
                dm[row - i + size] = true;
                tryPos(row + 1, size, pos);
                c[i] = false;
                dp[row + i] = false;
                dm[row - i + size] = false;
            }
        }
};

int main() {
    Solution a = Solution();
    a.solveNQueens(4);
}
