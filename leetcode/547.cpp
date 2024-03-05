#include <vector>
using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> isVisited(isConnected.size());
        int res = 0;
        for (auto i = 0; i < isConnected.size(); i++) {
            if (isVisited[i] == false) {
                res += 1;
                dfs(i, isConnected, isVisited);
            }
        }
        return res;
    }
    void dfs(int s, vector<vector<int>>& isConnected, vector<bool>& isVisited) {
        if (isVisited[s])
            return;
        isVisited[s] = true;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[s][i]) {
                dfs(i, isConnected, isVisited);
            }
        }
    }
};
