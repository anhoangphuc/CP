#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b, step) for (auto i = a; i <= b; i += step)
#define repr(i, a, b, step) for (auto i = a; i >= b; i -= step)
#define it(x, s) for (auto x:s)

int n, k;
string s;

//-----------------------------------------------------------
void openf() {
    cin >> n >> k;
    cin >> s;
}
//-----------------------------------------------------------
void process() {
    int i = s.find('*');
    int cnt = 1;
    while (true) {
        // cout << i << endl;
        int t = -1;
        rep(j, 1, k, 1) 
            if (i + j < s.length() && s[i + j] == '*')
                t = j;
        i = i + t;
        if (t == -1) break;
        cnt += 1;
        // cout << i << " " << t << endl;
    }
    cout << cnt << endl;
}
//-----------------------------------------------------------
int main() {
    // freopen("test.inp", "r", stdin);
    int test; 
    cin >> test;
    while (test--) {
        openf();
        process();
    }
}
