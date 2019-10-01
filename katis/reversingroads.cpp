#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define repr(i, a, b) for (auto i = a; i >= b; i--)
#define ll long long

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

const int NMAX = 53;
int n, m, cnt = 0, connectedComponent = 0;
vector<int> ds[NMAX];
int low[NMAX], num[NMAX];
stack<int> st;
bool incomp[NMAX];
vector<pair<int, int>> edges;
//----------------------------------------
void openf() {
    int u, v;
    rep(i, 0, m - 1) 
        ds[i].clear();
    edges.clear();
    rep(i, 1, n) {
        cin >> u >> v;
        ds[u].push_back(v);
        edges.push_back(make_pair(u, v));
        //cout << u << " " << v << endl;
    }
}
//----------------------------------------
void scc(int u, int cu, int cv) {
    st.push(u);
    incomp[u] = 1;

    low[u] = num[u] = ++cnt;
    for (auto v: ds[u]) {
        if (u == cu && v == cv) continue;
        if (num[v] == -1) {
            scc(v, cu, cv);
            low[u] = min(low[u], low[v]);
        } else if (incomp[v])
            low[u] = min(low[u], num[v]);
    }
    if (u == cv) {
        auto v = cu;
        if (num[v] == -1) {
            scc(v, cu, cv);
            low[u] = min(low[u], low[v]);
        } else if (incomp[v]) 
            low[u] = min(low[u], num[v]);
    }

    //cout << u << " " << low[u] << " " << num[u] << endl;
    if (num[u] == low[u]) {
        connectedComponent++;
        while (true) {
            auto curr = st.top();
            incomp[curr] = 0;
            st.pop();
            if (curr == u) break;
        }
    }
}
//----------------------------------------
bool isValid(int cu, int cv) {
    cnt = connectedComponent = 0;
    while (!st.empty()) st.pop();
    memset(num, -1, sizeof(num));
    memset(low, -1, sizeof(low));
    memset(incomp, 0, sizeof(incomp));

    rep(i, 0, m - 1) 
        if (num[i] == -1) scc(i, cu, cv);

    //cout << "CC " << connectedComponent << endl;
    return (connectedComponent == 1);
}
//----------------------------------------
void process() {
    if (isValid(-1, -1)) {
        cout << "valid";
        return;
    }
    for (auto x:edges) 
        if (isValid(x.first, x.second)) {
            cout << x.first << " " << x.second;
            return;
        }
    cout << "invalid";
}
//----------------------------------------
int main() {
    //freopen("test.inp", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase = 0;
    while (cin >> m) {
        cin >> n;
        openf();
        //cout << m << " " << n << endl;
        testCase++;
        cout << "Case " << testCase << ": ";
        process();
        cout << endl;
    }
}