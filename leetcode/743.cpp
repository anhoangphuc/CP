#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b, step) for (auto i = a; i < b; i += step)
#define repr(i, a, b, step) for (auto i = a; i > b; i -= step)

typedef pair<int, int> pii;

class Solution {
    public:
        vector<int> dis = vector<int>(103, -1);
        queue<pair<int, int>> q;
        vector<vector<pair<int, int>>> ds = vector<vector<pair<int, int>>>(103);
        int networkDeplayTime(vector<vector<int>>& times, int n, int k) {
            for (auto time: times)
                ds[time[0]].push_back(make_pair(time[1], time[2]));

            q.push(make_pair(k, 0));
            while (!q.empty()) {
                int u = q.front().first;
                int w = q.front().second;
                q.pop();
                if (dis[u] != -1 && dis[u] <= w)
                    continue;
                dis[u] = w;
                for (auto edge: ds[u]) {
                    int v = edge.first;
                    int c = edge.second;
                    q.push(make_pair(v, w + c));
                }
            }
            if (any_of(dis.begin() + 1, dis.begin() + 1 + n, [](int x) { return x == -1; })) {
                return -1;
            }
            else
                return *max_element(dis.begin() + 1, dis.begin() + 1 + n);
        }
};

int main() {
    Solution a = Solution(); 
    vector<vector<int>> v { { 1, 2, 1 } };
    cout << a.networkDeplayTime(v, 2, 2);
}
