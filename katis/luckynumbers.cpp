#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define repr(i, a, b) for (auto i = a; i >= b; i--)

int n, res = 0;
vector<int> a;
//----------------------------------------
bool validState(int i, int scs) {
    int tmp = 0;
    for (auto x: a) 
        tmp = (tmp * 10 + x) % scs;
    return (tmp * 10 + i) % scs == 0;
}
//----------------------------------------
void gen(int scs) {
    if (scs == n + 1) {
        res += 1;
        return;
    }

    rep(i, 0, 9) 
    if (!(scs == 1 && i == 0) && validState(i, scs)) {
        a.push_back(i);
        gen(scs + 1);
        a.pop_back();
    }
}
//----------------------------------------
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    gen(1);
    cout << res;
}