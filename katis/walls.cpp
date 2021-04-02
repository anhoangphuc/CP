#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define repr(i, a, b) for (auto i = a; i >= b; i--)

typedef pair<float, float> point;
float l, w, r;
int n, cover[33];
point walls[4];
set<int> s;
//----------------------------------------
void openf() {
    float px, py;
    cin >> l >> w >> n >> r;
    walls[0] = point(-l/2, 0);
    walls[1] = point(l/2, 0);
    walls[2] = point(0, -w/2);
    walls[3] = point(0, w/2);

    rep(i, 0, n - 1) {
        cin >> px >> py;
        cover[i] = 0;
        rep(j, 0, 3) {
            //cout << (pow(px - walls[j].first, 2) + pow(py - walls[j].second, 2)) << endl;
            if (pow(px - walls[j].first, 2) + pow(py - walls[j].second, 2) <= r * r)
                cover[i] += (1 << j);
        }
        
        //cout << i << " " << cover[i] << endl;
    }

    int res = 5;
    rep(i1, 0, n - 1)
    rep(i2, 0, n - 1)
    rep(i3, 0, n - 1)
    rep(i4, 0, n - 1) {
        s.clear();
        s.insert(i1); s.insert(i2); s.insert(i3); s.insert(i4);
        if ((cover[i1] | cover[i2] | cover[i3] | cover[i4]) == 15) {
            res = min(res, int(s.size()));
        }
    }

    if (res == 5) cout << "Impossible"; else cout << res;
}
//----------------------------------------
void process() {

}
//----------------------------------------
int main() {
    //freopen("test.inp", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    openf();
    process();
}