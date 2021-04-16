#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <utility>
using namespace std;

#define rep(i, a, b, step) for (auto i = a; i <= b; i += step)
#define repr(i, a, b, step) for (auto i = a; i >= b; i -= step)

const int NMAX = 2e5 + 3;
int n;
map<int, int> m;
priority_queue<pair<int, int>> pq;

void openf() {
    int u;
    cin >> n;
    m.clear();
    rep(i, 1, n, 1) {
        cin >> u;
        m[u] += 1;
    }
}

void process() {
    while (!pq.empty()) 
        pq.pop();
    for (auto const &p: m) 
        pq.push(make_pair(p.second, p.first));

    int sz = n;
    while (pq.size() > 1) {
        auto u1 = pq.top();
        pq.pop();
        auto u2 = pq.top();
        pq.pop();
        sz -= 2;
        u1.first -= 1;
        u2.first -= 1;
        
        if (u1.first != 0)
            pq.push(u1);
        if (u2.first != 0)
            pq.push(u2);
    }

    cout << sz << endl;
}


int main() {
//    freopen("test.inp", "r", stdin);
    int test;
    cin >> test;
    while (test--) {
        openf();
        process();
    }
}
