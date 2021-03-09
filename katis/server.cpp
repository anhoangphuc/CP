#include <bits/stdc++.h>
using namespace std;

int n, T;
int main() {
    int u, sum = 0;
    cin >> n >> T;
    for (int i = 1; i <= n; i++) {
        cin >> u;
        sum += u;
        if (sum > T) {
            cout << i - 1;
            return 0;
        }
    }
    if (sum <= T)
        cout << n;
}