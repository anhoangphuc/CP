#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b, step) for (auto i = a; i < b; i += step)
#define repr(i, a, b, step) for (auto i = a; i > b; i -= step)

const int dx[4] = { -1, 0, 1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

typedef pair<int, int> pii;

class Solution {
    public:
    queue<tuple<int, int, int>> q;
    int d[303][303][65];
    bool inside(int x, int y, int m, int n) {
        return (x >= 0 && x < m && y >= 0 && y < n);
    }
    int shortestPathAllKeys(vector<string>& grid) {
        auto numberOfKey = 0;
        rep(i, 0, grid.size(), 1)
            rep(j, 0, grid[i].length(), 1) 
                if (grid[i][j] == '&') {
                    d[i][j][0] = 1;
                    q.push(make_tuple(i, j, 0));
                } else if (grid[i][j] >= 'a' && grid[i][j] <= 'f')
                    numberOfKey += 1;
        
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            auto x = get<0>(u);
            auto y = get<1>(u);
            auto c = get<2>(u);
            if (c == (1 << numberOfKey) - 1)
                return d[x][y][c] - 1;
            rep(i, 0, 4, 1) {
                auto x1 = x + dx[i];
                auto y1 = y + dy[i];
                //outside the box, next item
                if (!inside(x1, y1, grid.size(), grid[0].length())) continue;
                //hit the wall, next item
                if (grid[x1][y1] == '#') continue;
                //hit the lock
                if (grid[x1][y1] >= 'A' && grid[x1][y1] <= 'F') {
                    // if dont have key
                    if ((c & (1 << (grid[x1][y1] - 'A'))) == 0)
                        continue;
                }
                auto c1 = c;
                // ifhit the key, collect the key
                if (grid[x1][y1] >= 'a' && grid[x1][y1] <= 'f')
                    c1 =  c | (1 << (grid[x1][y1] - 'A'));

                if (d[x1][y1][c1] != 0)
                    continue;
                d[x1][y1][c1] = d[x][y][c] + 1;
                q.push(make_tuple(x1, y1, c1));
            }
        }
        return -1;
    }
};

int main() {

}