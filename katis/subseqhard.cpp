#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define ll long long

int n;
map<ll, int> m;

//----------------------------------------
void process() {
    int u; ll s = 0, res = 0;
    cin.ignore();
    m.clear();
    m[0] = 1;
    cin >> n;
    rep(i, 1, n) {
        cin >> u;
        s += u;
        if (m.find(s - 47) != m.end()) 
            res += m[s - 47];
        m[s] = m.find(s) == m.end() ? 1 : m[s] + 1;
    }

    cout << res << endl;
}
//----------------------------------------
int main() {
    //freopen("test.inp", "r", stdin);
    int test;
    cin >> test;
    while (test--) {
        cin.ignore();
        process();
    }
}