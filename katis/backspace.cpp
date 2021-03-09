#include <bits/stdc++.h>
using namespace std;

char a[1000005];
//----------------------------------------
int main() {
    char ch;
    //freopen("test.inp", "r", stdin);
    int current = -1;
    while (cin >> ch) {
        if (ch != '<') a[++current] = ch;
        else current -= 1;
    }

    for (auto i = 0; i <= current; i++)
        cout << a[i];
}