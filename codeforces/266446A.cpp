#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define repr(i, a, b) for (auto i = a; i >=b; i--)

const int NMAX = 3e2 + 3;

int a[NMAX], n,  k;
ll f[NMAX][NMAX][NMAX];

//--------------------------------------------------
void openf() {
    freopen("bonus.inp", "r", stdin);
    freopen("bonus.out", "w", stdout);
    cin >> n >> k;
    rep(i, 1, n)
        cin >> a[i];
}

bool valid(int i, int j, int v) {
    return (i <= j && v * 2 <= (j - i + 1));
}

void process() {
    rep(i, 1, n - 1)
        f[i][i + 1][1] = abs(a[i] - a[i + 1]);
    
    rep(t, 2, n) 
        rep(i, 1, n - 2) {
            int j = i + t;
            if (j > n) break;
            for (int v = 1; v <=k; v++) {
                if (v * 2 > t + 1)
                    break;
                f[i][j][v] = max(f[i + 1][j][v], f[i][j - 1][v]);
                if (valid(i + 2, j, v - 1) && f[i][j][v] < f[i + 2][j][v - 1] + abs(a[i] - a[i + 1])) 
                    f[i][j][v] = f[i + 2][j][v - 1] + abs(a[i] - a[i + 1]);

                if (valid(i, j - 2, v - 1) && f[i][j][v] < f[i][j - 2][v - 1] + abs(a[j] - a[j - 1])) 
                    f[i][j][v] = f[i][j - 2][v - 1] + abs(a[j] - a[j - 1]);

                if (valid(i + 1, j - 1, v - 1) && f[i][j][v] < f[i + 1][j - 1][v - 1] + abs(a[i] - a[j])) 
                    f[i][j][v] = f[i + 1][j - 1][v - 1] + abs(a[i] - a[j]);
            }
        }
    cout << f[1][n][k];
}

int main() {
    openf();
    process();
}