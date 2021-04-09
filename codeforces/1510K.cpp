#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b, step) for (auto i = a; i <= b; i += step)
#define repr(i, a, b, step) for (auto i = a; i >= b; i -= step)
#define it(x, s) for (auto x:s)


const int NMAX = 1e3 + 3;
vector<int> a;
int n; 

void openf() {
    // freopen("test.inp", "r", stdin);
    int u;
    cin >> n;
    rep(i, 1, 2 * n, 1) {
        cin >> u;
        a.push_back(u);
    }
}
//--------------------------------------------------
void rotate(vector<int>&b, int t) {
    if (t == 0) {              //xoay kieu 1
        rep(i, 0, 2 * n - 1, 2) {
            swap(b[i], b[i + 1]);
        }
    }
    else {
            swap_ranges(b.begin(), b.begin() + n, b.begin() + n);
    }     
}
//--------------------------------------------------
void process() {
    vector<int> b(a);
    vector<int> c(a);
    sort(c.begin(), c.end());
    rep(num_iter, 0, 2 * n, 1) {
        // cout << num_iter << ": ";
        // it(x, b) 
        //     cout << x << " ";
        // cout << endl;
        if (c == b) {
            if (n & 1 == 1)
                cout << min(num_iter, 2 * n - num_iter);
            else 
                cout << min(num_iter, 4 - num_iter);
            return;
        }
        rotate(b, num_iter & 1);
    }
    cout << -1;
}
//--------------------------------------------------
int main() {
    openf();
    process();
}