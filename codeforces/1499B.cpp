#include <bits/stdc++.h>
using namespace std;

string s;
const int NMAX = 1e2 + 3;
bool f[NMAX];

void process() {
    memset(f, 0, sizeof(f));
    f[0] = 1;
    if (s.length() > 1) 
        f[1] = 1;
    for (int i = 2; i < s.size(); i++) {
        f[i] = (f[i - 1] && (s[i - 1] <= s[i]));
        f[i] = f[i] || (s[i - 2] <= s[i] && f[i - 2]);
    }
    cout << ((f[s.length() - 1] || (s.length() > 1 && f[s.length() - 2])) ? "YES": "NO") << endl;
}

int main() {
    // freopen("test.inp", "r", stdin);
    int test;
    cin >> test;
    while (test--) {
        cin >> s;
        process();
    }
}