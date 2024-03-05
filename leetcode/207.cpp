#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> m;
        vector<int> d(2003);
        for (auto p : prerequisites) {
            m[p[1]].push_back(p[0]);
            d[p[0]] += 1;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (d[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            auto top = q.front();
            q.pop();
            for (auto x : m[top]) {
                d[x] -= 1;
                if (d[x] == 0)
                    q.push(x);
            }
        }

        return *max_element(d.begin(), d.end()) == 0;
    }
};
