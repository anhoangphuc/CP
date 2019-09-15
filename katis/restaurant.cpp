#include <bits/stdc++.h>
using namespace std;

int n;

//----------------------------------------
void process() {
    int v1 = 0, v2 = 0, m;
    string order;
    while (n--) {
        cin >> order >> m;
        if (order[0] == 'D') {
            cout << "DROP 2 " << m << endl;
            v2 += m;
        }
        else {
            if (v1 >= m) {
                cout << "TAKE 1 " << m << endl;
                v1 -= m;
            }
            else {
                if (v1 != 0)
                    cout << "TAKE 1 " << v1 << endl;
                cout << "MOVE 2->1 " << v2 << endl;
                cout << "TAKE 1 " << m - v1 << endl;
                v1 = v2 - (m - v1);
                v2 = 0;
            }
        }
    }
    cout << endl;
}
//----------------------------------------
int main() {
    // freopen("test.inp", "r", stdin);
    while (cin >> n) {
        if (n == 0) break;
        process();
    }
}