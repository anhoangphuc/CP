#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = 0;
        for (auto g: graph) {
            for (auto x: g) {
                n = max(n, x);
            }
        }
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> isVisted(n + 1);
        dfs(0, res, graph, n, isVisted, cur);
        return res;
    }
    void dfs(int s, vector<vector<int>>& res, vector<vector<int>>& graph, int n, vector<bool> isVisited, vector<int> cur) {
        if (isVisited[s]) return;
        if (s == n) {
            cur.push_back(s);
            res.push_back(cur);
            return;
        }
        isVisited[s] = true;
        cur.push_back(s);
        for (auto x: graph[s]) {
            dfs(x, res, graph, n, isVisited, cur);
        }
        isVisited[s] = false;
        cur.pop_back();
    }
};
