#define fori(i, a, b, c) for (int i=a; i <= b; i += c)
#include <bits/stdc++.h>
using namespace std;

int main() {
    int numberOfDays, tempInDay, res = 0;
    cin >> numberOfDays;
    while (numberOfDays--) {
        cin >> tempInDay;
        res += (tempInDay < 0);
    }
    cout << res;
}