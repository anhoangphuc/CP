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

typedef complex<double> Point;

const int NMAX = 1e5 + 3;

int n, m;
vector<int> ds[NMAX];
//----------------------------------------
void openf() {

}
//----------------------------------------
void process() {
}
//----------------------------------------
int main() {
    freopen("test.inp", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    openf();
    process();
}