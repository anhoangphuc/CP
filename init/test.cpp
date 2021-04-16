#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s1;
    vector<int> s2(10);
    s1.insert(1);
    s1.insert(2);
    transform(s1.begin(), s1.end(), s2.begin(),
    [](int x) {return x;});
}
