#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define repr(i, a, b) for (auto i = a; i >= b; i--)
#define ll long long
#define iterate(x, z) for (auto x:z)
#define decon(a) show(a); for (auto x: a) cout << x << " "; cout << endl
#define debug(x) show(x); cout << x << " " << endl;
#define dearr(a, n) show(a); for (int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl
#define show(a) cout << #a << ": "

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int oo = 1e9 + 3;
struct Edge {
    int u, v, cost;
    Edge(int tu, int tv, int tcost) {
        u = tu; v = tv; cost = tcost;
    }
};

typedef complex<double> point;

const int NMAX = 1e5 + 3;

int n, m;
vector<int> ds[NMAX];
//----------------------------------------
void openf() {
}
//----------------------------------------
void process() {
    cin >> n;
    int u, v;

    int right = 2 * oo;
    int up = 2 * oo;
    int left = -2 * oo; 
    int down = -2 * oo;
    rep(rec, 1, n) {
        int left_r = 2 * oo;
        int right_r = -2 * oo;
        int up_r = -2 * oo;
        int down_r = 2 * oo;
        rep(i, 1, 4) {
            cin >> u >> v;
            left_r = min(left_r, v - u);
            right_r = max(right_r, v - u);
            up_r = max(up_r, u + v);
            down_r = min(down_r, u + v);
        }
        left = max(left, left_r);
        right = min(right, right_r);
        up = min(up, up_r);
        down = max(down, down_r);
    }


    left += 1; right -= 1; down += 1; up -= 1;

    //debug(left); debug(right); debug(up); debug(down);
    if (left > right || down > up) {
        cout << 0;
        return;
    } 

    ll tu = ((right - abs(right) % 2) - (left + abs(left) % 2)) / 2 + 1;
    ll tv = ((up - abs(up) % 2) - (down + abs(down) % 2)) / 2 + 1;
    
    //debug(tu);
    //debug(tv);

    ll res = tu * tv;
    res += (ll)(right - left + 1 - tu) * (up - down + 1 - tv);

    cout << res;
}
//----------------------------------------
int main() {
    //freopen("test.inp", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    openf();
    process();
}
