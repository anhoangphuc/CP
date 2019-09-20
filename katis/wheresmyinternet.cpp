#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
const int NMAX = 2e5 + 3;
int dj[NMAX], n, m;

//----------------------------------------
int find(int u) {
    return dj[u] < 0 ? u: dj[u] = find(dj[u]);
}
//----------------------------------------
void unionSet(int u, int v) {
    if (u == v) return;
    if (u > v) swap(u, v);
    dj[u] += dj[v];
    dj[v] = u;
}
//----------------------------------------
int main() {
    int u, v;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m; 
    rep(i, 1, n)
        dj[i] = -1;

    while (m--) {
        cin >> u >> v;
        int pu = find(u), pv = find(v);
        unionSet(pu, pv);
    }

    if (dj[1] == -n) 
        cout << "Connected";
    else {
        rep(i, 1, n)
            if (i != 1 && find(i) != 1)
                cout << i << endl;
    }

}