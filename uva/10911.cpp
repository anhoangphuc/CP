#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
using namespace std;

#define rep(i, a, b, step) for (auto i = a; i <= b; i += step)
#define repr(i, a, b, step) for (auto i = a; i >= b; i -= step)

const int NMAX = 18;
int n, px[NMAX], py[NMAX];
double f[1 << NMAX];


double dis(int i, int j) {
    return sqrt(pow(px[i] - px[j], 2) + pow(py[i] - py[j], 2));
}

void process() {
    rep(i, 0, (1 << 2 * n) - 1, 1)
        f[i] = -1;
    f[0] = 0;
    rep(i, 0, (1 << 2 * n) - 1, 1) {
        if (f[i] == -1) continue;
        rep(j1, 0, 2 * n - 1, 1)
            rep(j2, j1 + 1, 2 * n - 1, 1) 
            if (((i >> j1 & 1) == 0) && ((i >> j2 & 1) == 0)) {
                    int new_i = i + (1 << j1) + (1 << j2);
                    double d = f[i] + dis(j1, j2); 
                    if (f[new_i] == -1)
                        f[new_i] = d;
                    else 
                        f[new_i] = min(f[new_i], d);
            }
    }
}


int main() {
    freopen("test.inp", "r", stdin);
    int test; 
    test = 0;
    while (cin >> n) {
        if (n == 0) break;
        test += 1;
        string name;
        rep(i, 0, 2 * n - 1, 1) {
            cin >> name;
            cin >> px[i] >> py[i];
        }
        process();
        cout << fixed << setprecision(2);
        cout << "Case " << test << ": " << f[(1 << 2 * n) - 1] << endl;
    }
}
