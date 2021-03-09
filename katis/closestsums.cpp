#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define repr(i, a, b) for (auto i = a; i >= b; i--)

const int NMAX = 1e3 + 3;

int n, m, a[NMAX];
//----------------------------------------
string process(int u) {
    int re = 2e9;
    rep(i, 1, n)
        rep(j, i + 1, n) 
            if (abs(a[i] + a[j] - u) < abs(re - u)) re = a[i] + a[j];

    return to_string(re);
}
//----------------------------------------
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("test.inp", "r", stdin);

    int testCase = 0, u;
    while (cin >> n) {
        testCase += 1;
        cout << "Case " + to_string(testCase) + ":" << endl;
        rep(i, 1, n) cin >> a[i];
        cin >> m;
        while (m--) {
            cin >> u;
            cout << "Closet sum to " + to_string(u) + " is " + process(u) + "." <<  endl;
        }
    }
}