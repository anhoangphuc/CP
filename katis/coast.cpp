#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define repr(i, a, b) for (auto i = a; i >= b; i--)
#define ll long long

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int NMAX = 1e3 + 3;

int m, n;
char a[NMAX][NMAX];
bool sea[NMAX][NMAX];
//----------------------------------------
void openf() {
    cin >> m >> n;
    rep(i, 1, m) 
    rep(j, 1, n)
    cin >> a[i][j];
}
//----------------------------------------
bool inside(int u, int v) {
    return (u >= 1 && u <= m && v >=1 && v <= n);
}
//----------------------------------------
void DFS(int u, int v) {
    if (sea[u][v]) return;
    if (a[u][v] == '1') return;
    sea[u][v] = 1;

    rep(i, 0, 3) {
        int du = u + dx[i];
        int dv = v + dy[i];
        if (inside(du, dv))
            DFS(du, dv);
    }
}
//----------------------------------------
void process() {
    rep(i, 1, m) a[i][0] = a[i][n + 1] = '0';
    rep(i, 1, n) a[0][i] = a[m + 1][i] = '0';

    rep(i, 1, m) DFS(i, 0), DFS(i, n + 1);
    rep(i, 1, n) DFS(0, i), DFS(m + 1, i);

    int res = 0;
    rep(u, 1, m)
    rep(v, 1, n) { 
        rep(i, 1, 2) {
            int du = u + dx[i];
            int dv = v + dy[i];
            if (inside(du, dv))
            res += (sea[u][v ]!= sea[du][dv]);
        }
        if (u == 1) res += (sea[u][v] ^ 1);
        if (u == m) res += (sea[u][v] ^ 1);
        if (v == 1) res += (sea[u][v] ^ 1);
        if (v == n) res += (sea[u][v] ^ 1);
    }
    cout << res; 

	/*rep(u, 1, m) {
		rep(v, 1, n)  
			cout << sea[u][v];
		cout << endl;
	}*/
}
//----------------------------------------
int main() {
    //freopen("test.inp", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
    int testCase;
    cin >> testCase;
    rep(test, 1, testCase) {
        openf();
        process();
    } */
    
    openf();
    process();
}
