#include <bits/stdc++.h>
using namespace std;

const int NMAX = 1e6 + 3;
int n, m, sum[NMAX], a[NMAX], blockSize;

//----------------------------------------
void update(int i) {
    sum[i / blockSize] += (a[i] ^ 1) - a[i];
    a[i] ^= 1;
}
//----------------------------------------
int getResult(int l, int r) {
    int res = 0;
    while (l <= r and l % blockSize != 0) {
        res += a[l];
        l += 1;
    }
    while (l + blockSize - 1 <= r) {
        res += sum[l / blockSize];
        l += blockSize;
    }

    while (l <= r) {
        res += a[l];
        l += 1;
    }

    return res;
}
//----------------------------------------
int main() {
    string ch; int u, v;
    cin >> n >> m;
    blockSize = sqrt(n);
    while (m--) {
        cin >> ch;
        if (ch == "F") {
            cin >> u;
            update(u - 1);
        }
        else {
            cin >> u >> v;
            cout << getResult(u - 1, v - 1) << endl;
        }
    }
}