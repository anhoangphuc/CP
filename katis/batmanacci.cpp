#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define repr(i, a, b) for (auto i = a; i >= b; i--)
#define ll long long

const ll oo = 1e18;
const int NMAX = 1e5 + 3;
ll a[NMAX], k;
int n;
//----------------------------------------
char getResult(int n, ll k) {
    while (n >= 3) {
        if (k > a[n - 2]) {
            k -= a[n - 2];
            n -= 1;
        } else n -= 2;
    }

    if (n == 1) return 'N';
    return 'A';
}
//----------------------------------------

void process() {
    a[1] = a[2] = 1;
    rep(i, 3, 1e5) {
        if (a[i - 1] <= oo - a[i - 2])
            a[i] = a[i - 2] + a[i - 1];
        else a[i] = oo;
    }

    cout << getResult(n, k);
}
//----------------------------------------
int main() {
    // freopen("test.inp", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    process();
}