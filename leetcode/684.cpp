#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> m(n + 1);
        vector<int> d(n + 1);
        queue<int> q;
        vector<bool> cantRemove(n + 1);
        vector<int> parent(n + 1);
        for (auto edge : edges) {
            d[edge[0]] += 1;
            d[edge[1]] += 1;
            m[edge[0]].push_back(edge[1]);
            m[edge[1]].push_back(edge[0]);
        }
        for (auto i = 1; i <= n; i++) {
            if (d[i] == 1) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            cantRemove[t] = true;
            for (auto x: m[t]) {
                if (parent[t] == x) continue;
                parent[x] = t;
                d[x] -= 1;
                if (d[x] == 1) q.push(x);
            }
        }

        for (auto i = edges.size() - 1; i >= 0; i--) {
            auto edge = edges[i];
            if (!cantRemove[edge[0]] && !cantRemove[edge[1]]) return edge;
        }
        return edges[0];
    }
};
