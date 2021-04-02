#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define repr(i, a, b) for (auto i = a; i >= b; i--)
const int NMAX = 1e5 + 3;

map<string, int> mapName;
int n;
int dj[NMAX];
//----------------------------------------
int getParent(int u) {
    return dj[u] < 0 ? u : dj[u] = getParent(dj[u]);
}
//----------------------------------------
int unionSet(int u, int v) {
    if (u == v) return abs(dj[u]);

    if (dj[u] > dj[v]) swap(u, v);
    dj[u] += dj[v];
    dj[v] = u;

    return abs(dj[u]);
}
//----------------------------------------
void process() {
    cin >> n;
    string s1, s2;
    int cnt = 0;
    mapName.clear();
    rep(i, 1, n) { 
        cin >> s1 >> s2;
        if (mapName.find(s1) == mapName.end()) {
            mapName[s1] = ++cnt;
            dj[cnt] = -1;
        }
        if (mapName.find(s2) == mapName.end()) {
            mapName[s2] = ++cnt;
            dj[cnt] = -1;
        }

        int u = getParent(mapName[s1]);
        int v = getParent(mapName[s2]);

        cout << unionSet(u, v) << endl;
    }
}
//----------------------------------------
int main() {
    int test;
    //freopen("test.inp", "r", stdin);
    cin >> test;
    while (test--) {
        process();
    }
}