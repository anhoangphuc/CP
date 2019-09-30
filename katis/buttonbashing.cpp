#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define repr(i, a, b) for (auto i = a; i >= b; i--)
#define ll long long

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

const int NMAX = 36e2 + 4;

int n, t;
int d[NMAX];
int a[20];
queue<int> q;
//----------------------------------------
void openf() {
    cin >> n >> t;
    rep(i, 1, n)
        cin >> a[i];
}
//----------------------------------------
void BFS(int root) {
    memset(d, 0, sizeof(d));
    d[root] = 1;
    q.push(root);

    while (!q.empty()) {
        auto u = q.front();
        rep(i, 1, n) {
            int v = min(3600, max(0, u + a[i]));
            if (d[v] == 0) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
        q.pop();
    }
}
//----------------------------------------
void process() {
    memset(d, 0, sizeof(d));
    BFS(0);

    rep(i, t, 3600)
        if (d[i]) {
            cout << d[i] - 1 <<  " " << i - t << endl;
            break;
        }
} 
//----------------------------------------
int main() {
    //freopen("test.inp", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase;
    cin >> testCase;
    rep(test, 1, testCase) {
        openf();
        process();
    }
}