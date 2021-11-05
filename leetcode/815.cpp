#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b, step) for (auto i = a; i < b; i += step)
#define repr(i, a, b, step) for (auto i = a; i > b; i -= step)

typedef pair<int, int> pii;

class Solution {
    public:
    bool isUsed[503];
    int d[1000003];
    queue<int> q;
    vector<int> routeList[100003];
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        for (auto i = 0; i < routes.size(); i++)
            for (auto u: routes[i])
                routeList[u].push_back(i);

        d[source] = 1;
        q.push(source);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (auto routeIndex: routeList[u]) {
                if (isUsed[routeIndex]) continue;
                isUsed[routeIndex] = true;
                for (auto v: routes[routeIndex]) {
                    if (d[v] != 0) continue;
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        return d[target] - 1;

    }
}

int main() {

}