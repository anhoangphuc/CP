#define ll long long

#include <bits/stdc++.h>
using namespace std;

int main() {
    ll first_number, second_number;
    while (cin >> first_number >> second_number) {
        cout << abs(second_number - first_number) << endl;
    }
}