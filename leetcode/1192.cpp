#include <vector>
using namespace std;
class Solution {
public:
    vector<int> start;
    vector<int> end;
    vector<vector<int>> res;
    vector<vector<int>> m;
    vector<int> parent;
    vector<int> topReach;
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        start.resize(n);
        end.resize(n);
        m.resize(n);
        parent.resize(n);
        for (auto connection : connections) {
            m[connection[0]].push_back(connection[1]);
            m[connection[1]].push_back(connection[0]);
        }
        topReach.resize(n);
        int scount = 1;
        int ecount = 1;
        dfs(0, scount, ecount);
        return res;
    }

    void dfs(int s, int& scount, int& ecount) {
        start[s] = scount;
        topReach[s] = scount;
        scount += 1;
        for (auto x : m[s]) {
            // x-s is processed
            if (parent[s] == x)
                continue;
            // x is already search
            if (start[x] > 0) {
                topReach[s] = min(topReach[s], topReach[x]);
                // not yet finsh the dfs
                if (end[s] == 0)
                    continue;
                res.push_back({ s, x });
                continue;
            }
            parent[x] = s;
            dfs(x, scount, ecount);
            topReach[s] = min(topReach[s], topReach[x]);
            // Cannot reach s from x
            if (topReach[x] > start[s]) {
                res.push_back({s, x});
            }
        }
        end[s] = ecount;

        ecount += 1;
    }
};
