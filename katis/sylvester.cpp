#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define repr(i, a, b) for (auto i = a; i >= b; i--)
#define ll long long

ll n, x, y, w, h;
//----------------------------------------
int getItem(ll n, ll px, ll py) {
    int cnt = 1; ll si = n;
    while (si != 1) {
        if (px >= si/2 && py >= si/2) cnt *= -1;
        px %= si/2; py %= si/2;
        si /= 2;
    }

    return cnt;
}
//----------------------------------------
void process() {
    rep(i, 0, h - 1) {
        rep(j, 0, w - 1)
        cout << getItem(n, y + i, x + j) << " ";
        cout << endl;
    }
    cout << endl;
}
//----------------------------------------
int main() {
    //freopen("test.inp", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase;
    cin >> testCase;
    while (testCase--) {
        cin >> n >> x >> y >> w >> h;
        process();
    }
}