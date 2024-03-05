#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> m(n);
        for (auto edge : edges) {
            m[edge[0]].push_back(edge[1]);
            m[edge[1]].push_back(edge[0]);
        }
        vector<bool> inStack(n);
        vector<bool> isVisited(n);
        vector<int> parent(n, -1);
        auto res = dfs(0, m, inStack, isVisited, parent);
        if (res == false)
            return false;
        return (true && (find(isVisited.begin(), isVisited.end(), false) ==
                         isVisited.end()));
    }
    bool dfs(int s, vector<vector<int>> const& m, vector<bool> inStack,
             vector<bool>& isVisited, vector<int>& parent) {
        if (isVisited[s]) {
            if (inStack[s])
                return false;
            return true;
        }
        inStack[s] = true;
        isVisited[s] = true;
        for (auto x : m[s]) {
            if (parent[s] == x)
                continue;
            parent[x] = s;
            auto res = dfs(x, m, inStack, isVisited, parent);
            // e[x][s] = false;
            if (res == false)
                return false;
        }
        inStack[s] = false;
        return true;
    }
};
