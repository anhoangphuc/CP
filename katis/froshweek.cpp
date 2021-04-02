#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define repr(i, a, b) for (auto i = a; i >= b; i--)
#define ll long long

const int NMAX = 1e6 + 3;

vector<int> a, b;
int n;
int ft[NMAX];
map<int, int> m;
//----------------------------------------
void openf() {
    //freopen("test.inp", "r", stdin);
    cin >> n;
    int u;
    rep(i, 1, n) {
        cin >> u;
        a.push_back(u);
    }
}
//----------------------------------------
int getResult(int x) {
    int re = 0;
    while (x > 0) {
        re += ft[x];
        x -= x & (-x);
    }

    return re;
}
//----------------------------------------
void updateTree(int x) {
    while (x < NMAX) {
        ft[x] += 1;
        x += x & (-x);
    }
}
//----------------------------------------
void process() {
    b = a;
    sort(b.begin(), b.end());

    int cnt = 0;
    for (auto x: b) 
        m[x] = ++cnt;

    ll res = 0;
    cnt = 0;
    for (auto x: a) {
        int v = m[x];
        res += cnt - getResult(v); 
        cnt += 1;
        updateTree(v);
    }

    cout << res;
}
//----------------------------------------
int main() {
    openf();
    process();
}