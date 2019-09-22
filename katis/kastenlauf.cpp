#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define repr(i, a, b) for (auto i = a; i >= b; i--)

const int NMAX = 1e2 + 5;
int posx[NMAX], posy[NMAX], n, dj[NMAX];
//----------------------------------------
void openf() {
    cin >> n;
    cin >> posx[1] >> posy[1];
    cin >> posx[2] >> posy[2];
    rep(i, 1, n)
        cin >> posx[2 + i] >> posy[2 + i];
}
//----------------------------------------
bool connected(int u, int v) {
    return (abs(posx[u] - posx[v]) + abs(posy[u] - posy[v]) <= 1000);
}
//----------------------------------------
int findParent(int u) {
    return (dj[u] < 0 ? u: dj[u] = findParent(dj[u]));
}
//----------------------------------------
void unionSet(int u, int v) {
    if (u == v) return;
    if (dj[u] > dj[v]) swap(u, v);
    dj[u] += dj[v];
    dj[v] = u;
}
//----------------------------------------
void process() {
    memset(dj, -1, sizeof(dj));
    rep(u, 1, n + 2)
        rep(v, 1, n + 2)
            if (connected(u, v)) {
                int nu = findParent(u), nv  = findParent(v);
                unionSet(nu, nv);
            }

    if (findParent(1) == findParent(n + 2)) cout << "happy";
    else cout << "sad";
    cout << endl;
}
//----------------------------------------
int main() {
    //freopen("test.inp", "r", stdin);
    int test;
    cin >> test;
    while (test--) {
        openf();
        process();
    }
}