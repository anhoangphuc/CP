#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(auto i = a; i <= b; i++)

int n;
int h[257];
set<string> b;
map<string, int> m;

//----------------------------------------
int hashString(string s) {
    int res = 0;
    for (auto x: s) {
        res ^= (int(x));
    }

    return res;
}
//----------------------------------------
void process() {
    string s;
    memset(h, 0, sizeof(h));
    b.clear();
    m.clear();
    int sub = 0;

    cin.ignore();
    rep(i, 1, n) {
        getline(cin, s);
        h[hashString(s)]++;
        b.insert(s);
        if (m.find(s) == m.end())
            m[s] = 1;
        else {
            sub += m[s];
            m[s]++;
        }
    }    

    int totalCollide = 0;
    rep(i, 0, 255) 
        totalCollide += (h[i] * (h[i] - 1)) / 2;

    cout << b.size() << " " << totalCollide - sub << endl;
}
//----------------------------------------
int main() {
    // freopen("test.inp", "r", stdin);
    while (cin >> n) {
        if (n == 0) break;
        process();
    }
}