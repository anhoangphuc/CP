#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define repr(i, a, b) for (auto i = a; i >= b; i--)
#define ll long long

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n;
vector<string> pathTrace;
map<string, vector<string>> routes;
set<string> setLocation;
string startLocation, finishLocation;
bool ok = false;
//----------------------------------------
void openf() {
    string s;
    cin >> n;
    cin.ignore();
    rep(i, 1, n) {
        pathTrace.clear();
        getline(cin, s);
        string tmp = "";
        for (auto x:s) {
            if (x == ' ') {
                pathTrace.push_back(tmp);
                tmp = "";
            }
            else tmp += x;
        }
        pathTrace.push_back(tmp);
        rep(j, 1, pathTrace.size() - 1) {
            routes[pathTrace[0]].push_back(pathTrace[j]);  
            routes[pathTrace[j]].push_back(pathTrace[0]);
        }
    }
}
//----------------------------------------
void DFS(string u) {
    if (setLocation.find(u) != setLocation.end()) return;
    setLocation.insert(u);
    pathTrace.push_back(u);

    if (u == finishLocation) {
        ok = 1;
        for (auto x: pathTrace) cout << x << " ";
    }

    for (auto v: routes[u]) DFS(v);

    pathTrace.pop_back();
}
//----------------------------------------
void process() {
    pathTrace.clear();
    cin >> startLocation >> finishLocation;
    DFS(startLocation);

    if (!ok) cout << "no route found";
}
//----------------------------------------
int main() {
    freopen("test.inp", "r", stdin);
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