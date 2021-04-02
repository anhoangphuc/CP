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
#define fi first
#define se second

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int oo = 1e9 + 3;
typedef complex<double> Point;
struct Edge {
    int u, v, cost;
    Edge(int tu, int tv, int tcost) {
        u = tu; v = tv; cost = tcost;
    }
};
struct Line {
    Point first, second;
    bool isLine;
    Line(Point tfirst, Point tsecond, bool tisLine=true) {
        first = tfirst; second = tsecond; isLine = tisLine;
    }
};


const int NMAX = 1e3 + 3;

int n, m;
Point a[NMAX], b[NMAX];
//----------------------------------------
void openf() {
    double u, v;
    cin >> n >> m;
    rep(i, 1, n) {
        cin >> u >> v;
        a[i] = Point(u, v);
    }
    rep(i, 1, m) {
        cin >> u >> v;
        b[i] = Point(u, v);
    }
}
//----------------------------------------
double dotProduct(Point PointA, Point PointB) {
    return real(PointA) * real(PointB) + imag(PointA) * imag(PointB);
}
//----------------------------------------
Point getClosestPoint(Point pointA, Line line) {
    if (line.isLine) {
        if (dotProduct(line.fi - line.se, pointA - line.fi) > 0) return line.fi;
        if (dotProduct(line.se - line.fi, pointA - line.se) > 0) return line.se;
    }

    double t = dotProduct(line.se - line.fi, pointA - line.fi) / norm(line.se - line.fi);
    return line.fi + t * (line.se - line.fi);
}
//----------------------------------------
double getDistance(Point pointA, Line line) {
    auto closestPoint = getClosestPoint(pointA, line);
    return abs(closestPoint - pointA);
}
//----------------------------------------
void process() {
    double res = 1e10;
    rep(i, 1, n) {
        rep(j, 1, m - 1)
            res = min(res, getDistance(a[i], Line(b[j], b[j + 1])));
    }

    rep(i, 1, m)
        rep(j, 1, n - 1)
            res = min(res, getDistance(b[i], Line(a[j], a[j + 1])));

    printf("%.3lf", res);
}
//----------------------------------------
int main() {
    //freopen("test.inp", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    openf();
    process();
}