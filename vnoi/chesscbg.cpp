#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define repr(i, a, b) for (auto i = a; i >= b; i--)
#define ll long long

vector<pair<int, int>> pa, pb;
vector<int> perm;
//----------------------------------------
void openf() {
    char ch;
    rep(i, 1, 4)
    rep(j, 1, 4) {
        cin >> ch;
        if (ch == '1') {
            pa.push_back(make_pair(i, j));
            //cout << i << " " << j << endl;
        }
    }

    rep(i, 1, 4)
    rep(j, 1, 4) {
        cin >> ch;
        if (ch == '1') {
            //cout << i << " " << j << endl;
            pb.push_back(make_pair(i, j));
        } 
    }
}
//----------------------------------------
void process() { 
    rep(i, 0, 7) perm.push_back(i);
    int res = 1e6;
    do {
        int cnt = 0;
        //rep(i, 0, 7) cout << perm[i] << " ";
        //cout << endl;
        rep(i, 0, 7) 
            cnt += abs(pa[perm[i]].first - pb[i].first) + abs(pa[perm[i]].second - pb[i].second);
        res = min(res, cnt);
    } while (next_permutation(perm.begin(), perm.end()));
    cout << res;
}
//----------------------------------------
int main() {
    //freopen("test.inp", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    openf();
    process();
}