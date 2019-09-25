#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define repr(i, a, b) for (auto i = a; i >= b; i--)
#define ll long long

int n;
int main() {
    //freopen("test.inp", "r", stdin);
    int testCase;
    ll u, tmp;
    cin >> testCase;
    while (testCase--) {
        cin >> n; 
        tmp = 0;
        rep(i, 1, n) {
            cin >> u;
            tmp = (tmp + u % n) % n; 
        }
        if (tmp == 0) cout << "YES"; else cout << "NO";

        cout << endl;
    }
}