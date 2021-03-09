#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define repr(i, a, b) for (auto i = a; i >= b; i--)
#define ll long long

int n; 
vector<int> a, b;
//----------------------------------------
void process() {

}
//----------------------------------------
void process(int testCase) {
    cout << "Case #" + to_string(testCase) + ": ";
    ll res = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());

    rep(i, 0, a.size() - 1)
        res += (ll)a[i] * b[i];
    
    cout << res << endl;
}
//----------------------------------------
int main() {
    freopen("test.inp", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase, u;
    cin  >> testCase;
    rep(i, 1, testCase) {
        a.clear();
        b.clear();
        cin >> n;
        rep(j, 1, n) {
            cin >> u;
            a.push_back(u);
        }
        rep(j, 1, n) {
            cin >> u;
            b.push_back(u);
        }
        process(i);
    }
}
