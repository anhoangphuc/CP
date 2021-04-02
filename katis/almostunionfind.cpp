#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define repr(i, a, b) for (auto i = a; i >= b; i--)
#define ll long long

const int NMAX = 1e5 + 3;
int n, m;
set<int> s[NMAX];
int place[NMAX];
ll sum[NMAX];

//----------------------------------------
void unionSet(int u, int v) {
    int pu = place[u], pv = place[v];
    if (pu == pv) return; 

    if (s[pu].size() <= s[pv].size()) swap(pu, pv);

    for (auto x: s[pv]) {
        place[x] = pu;
        sum[pu] += x;
        s[pu].insert(x);
    }

    s[pv].clear();
    sum[pv] = 0;

    //rep(i, 1, n) 
        //cout << place[i] << " ";
    //cout << endl;
}
//----------------------------------------
void getResult(int u) {
    int pu = place[u];
    cout << s[pu].size() << " " << sum[pu] << endl;
}
//----------------------------------------
void unionPointToSet(int u, int v) {
    int pu = place[u], pv = place[v];
    s[pu].erase(u); s[pv].insert(u);
    sum[pu] -= u; sum[pv] += u;
    place[u] = pv;
    //rep(i, 1, n) 
        //cout << place[i] << " ";
    //cout << endl;
}
//----------------------------------------
int main() {
    //freopen("test.inp", "r", stdin);
    int t, u, v;
    while (cin >> n >> m) {
        rep(i, 1, n) {
            place[i] = i;
            sum[i] = i;
            s[i].clear();            
            s[i].insert(i);
        }

        rep(i, 1, m) {
            cin >> t;
            //cout << i << endl;
            if (t == 1) {
                cin >> u >> v;
                unionSet(u, v);
            }
            else if (t == 2) {
                cin >> u >> v;
                unionPointToSet(u, v);
            } 
            else {
                cin >> u;
                getResult(u);
            }
        }
    }
}