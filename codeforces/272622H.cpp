#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define repr(i, a, b) for (auto i = a; i <= b; i--)

const int NMAX = 1e3 + 3;

int x, a, b, y, n;
pair<int, int> f[NMAX][NMAX];

void openf() {
    cin >> x >> a >> y >> b >> n;
}
//--------------------------------------------------
pair<int, int> newState(pair<int, int> oldState, int value, int mid) {
    return (oldState.second + value < mid) ?
    make_pair(oldState.first, oldState.second + value) : make_pair(oldState.first + 1, 0); 
}
//--------------------------------------------------
bool check(int mid) {
    rep(i, 0, x)
        rep(j, 0, y)
            f[i][j] = make_pair(0, 0);

    rep(i, 0, x)
        rep(j, 0, y) {
            if (f[i][j].first == n)
                return true;
            if (i < x)
                f[i + 1][j] = max(f[i + 1][j], newState(f[i][j], a, mid));
            if (j < y)
                f[i][j + 1] = max(f[i][j + 1], newState(f[i][j], b, mid));
        }

    return false;    
}
//--------------------------------------------------
void process() {
    int l = 0, r = x * a + y * b, res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            res = mid;
            l = mid + 1;
        } else r = mid - 1;
    }

    cout << res << endl;
}
//--------------------------------------------------
int main() {
    freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    for (int t = 1; t <=2; t++) {
        openf();
        process();
    }
}