#define fori(i, a, b, c) for (int i=a; i <= b; i += c)
#include <bits/stdc++.h>
using namespace std;

int n, a[1003];

//----------------------------------------
void openf() {
    cin >> n;
    fori(i, 1, n, 1) 
        cin >> a[i];
}
//----------------------------------------
void process() {
    sort(a + 1, a + n + 1);
    int i = 1;
    while (i <= n) {
        if (i >= n - 1) {
            cout << a[i] << " ";
            i++;
        } 
        else if (a[i + 2] - 2 != a[i]) {
            cout << a[i] << " ";
            i++;
        }
        else {
            cout << a[i] << "-";
            int j = i + 2;
            while (j < n && a[j] + 1 == a[j + 1]) j++;
            cout << a[j] << " ";
            i = j + 1;
        }
    }
}
//----------------------------------------
int main() {
    openf();
    process();
}