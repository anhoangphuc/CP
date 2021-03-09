#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define repr(i, a, b) for (auto i = a; i >= b; i--)
#define ll long long

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

const int NMAX = 1e4 + 3;

int n, m, connectedComponent = 0, cnt = 0;
vector<int> ds[NMAX];
int low[NMAX], num[NMAX];
stack<int> st;
bool inSt[NMAX];
//----------------------------------------
void openf() {
    int u, v;
    cin >> n >> m;   
    rep(i, 1, m) {
        cin >> u >> v;
        ds[u].push_back(v);
    }
}
//----------------------------------------
void Tarjan(int u) {
    low[u] = num[u] = ++cnt;
    st.push(u);
    inSt[u] = 1;

    for (auto v: ds[u]) {
        if (num[v] == -1) {
            Tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (inSt[v])
            low[u] = min(low[u], num[v]);
    }

    if (low[u] == num[u]) {
        connectedComponent++;
        while (true) {
            auto current = st.top();
            st.pop();
            inSt[u] = 0;
            if (current == u) break;
        }
    }
}
//----------------------------------------
void process() {
    memset(low, -1, sizeof(low));
    memset(num, -1, sizeof(num));

    connectedComponent = 0;
    rep(u, 1, n) 
        if (num[u] == -1) Tarjan(u);
    
    cout << connectedComponent;
}
//----------------------------------------
int main() {
    freopen("test.inp", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    openf();
    process();
}