#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define repr(i, a, b) for (auto i = a; i >= b; i--)
#define ll long long

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

const int NMAX = 1e5 + 3;
int n, res = 0, cnt = 0;
vector<int> ds[NMAX];
map<string, int> mapFile;
map<int, string> mapInd;
vector<string> listFile;
queue<int> q;
vector<int> dependance;
bool inQueue[NMAX];
int deg[NMAX];
//----------------------------------------
int getInd(string fileName) {
    if (!mapFile[fileName]) {
        mapFile[fileName] = ++cnt;
        mapInd[cnt] = fileName;
    }

    return mapFile[fileName];
}
//----------------------------------------
void openf() {
    string s;
    cin >> n; 
    cin.ignore();
    rep(depen, 1, n) {
        getline(cin, s);
        string tmp = "";
        listFile.clear();
        for (auto x: s) {
            if (x != ' ') tmp += x;
            else {
                if (tmp != "") listFile.push_back(tmp);
                tmp = "";
            }
        }

        if (tmp != " ") listFile.push_back(tmp);
    
        listFile[0] = listFile[0].substr(0, listFile[0].length() - 1);

        rep(i, 1, listFile.size() - 1) {
            ds[getInd(listFile[i])].push_back(getInd(listFile[0]));
            deg[getInd(listFile[0])]++;
        }
    }
}
//----------------------------------------
void DFS(int u) {
    if (inQueue[u]) return;
    inQueue[u] = 1;
    for (auto v: ds[u]) DFS(v);
}
//----------------------------------------
void process() {
    string s;
    cin >> s;

    DFS(getInd(s));

    rep(i, 1, n) if (deg[i] == 0) 
        q.push(i);

    while (!q.empty()) {
        auto u = q.front();
        for (auto v: ds[u]) {
            deg[v]--;
            if (deg[v] == 0) q.push(v);
        }
        dependance.push_back(u);
        q.pop();
    }

    for (auto x: dependance) {
        if (inQueue[x]) cout << mapInd[x] << endl;
    }
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