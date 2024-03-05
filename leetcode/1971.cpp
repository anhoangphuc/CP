#include <vector>
using namespace std;
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<vector<int>> m(n);
        for (auto edge : edges) {
            m[edge[0]].push_back(edge[1]);
            m[edge[1]].push_back(edge[0]);
        }
        vector<bool> isVisited(n);
        dfs(source, m, isVisited);
        return isVisited[destination];
    }

    void dfs(int s, vector<vector<int>>& m, vector<bool>& isVisited) {
        if (isVisited[s])
            return;
        isVisited[s] = true;
        for (auto x : m[s]) {
            dfs(x, m, isVisited);
        }
    }
};
