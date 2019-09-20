#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)

int m, r;
const int NMAX = 1e5 + 3;
int b[NMAX*2], pos[NMAX];
//----------------------------------------
int getResult(int x) {
    int re = 0;
    while (x > 0) {
        re += b[x];
        x -= (x & (-x));
    }
    return re;
}
//----------------------------------------
void update(int x, int value) {
    while (x < NMAX * 2) {
        b[x] += value;
        x += (x & (-x));
    }
}
//----------------------------------------
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test, u;
    // freopen("test.inp", "r", stdin);
    cin >> test; 
    while (test--) {
        memset(b, 0, sizeof(b));
        memset(pos, 0, sizeof(pos));
        int uniqueValueNumber = 0;
        cin >> m >> r;
        rep(i, 1, m) {
            update(i, 1);
            pos[i] = m - i + 1;
        }
        rep(i, 1, r) {
            cin >> u;
            cout << m - getResult(pos[u]) << " ";
            update(pos[u], -1);
            update(i + m, 1);
            pos[u] = i + m;
        }
        cout << endl;
    }
}