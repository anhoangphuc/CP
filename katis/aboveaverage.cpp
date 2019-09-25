#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define repr(i, a, b) for (auto i = a; i >= b; i--)

int n;
vector<int> a;


//----------------------------------------
void process() {
    int cnt = 0, sum = 0;
    for (auto x: a) sum += x;
    for (auto x:a) cnt += x * a.size() > sum;

    printf("%.3f%%\n", float(cnt) / a.size() * 100);
}
//----------------------------------------
int main() {
    int test, u;
    //freopen("test.inp", "r", stdin);
    cin >> test;
    while (test--) {
        cin >> n;
        a.clear();
        rep(i, 1, n) {
            cin >> u;
            a.push_back(u);
        }
        process();
    }
}