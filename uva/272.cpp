#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    freopen("test.inp", "r", stdin);
    int cnt = 0;
    while (getline(cin, s)) {
        for (auto x: s) {
            if (x == '"') {
                if (cnt == 0)
                    cout << "``";
                else
                    cout << "''";
                cnt ^= 1;
            }
            else cout << x;
        }
        cout << endl;
    }
}