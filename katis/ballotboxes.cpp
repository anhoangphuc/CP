#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define repr(i, a, b) for (auto i = a; i >= b; i--)
#define ll long long

const int NMAX = 5e5 + 3;
int n, b, a[NMAX];
//----------------------------------------
bool check(int x) {
    int cnt = 0;
    rep(i, 1, n) 
        cnt += (a[i] - 1) / x + 1;
    return (cnt <= b);
}
//----------------------------------------
void process() {
    int l = 1, r = 5e6, res = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << res << endl;
}
//----------------------------------------
int main() {
    //freopen("test.inp", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> n >> b) {
        if (n == -1) break;
        rep(i, 1, n) cin >> a[i];
        process();
    }
}