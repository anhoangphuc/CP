#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {1, 2, 1, 3};
    vector<int> b = {10};
    b.insert(b.begin(), a.begin(), a.end());
    for (auto x: b)
        cout << x << endl;
}
