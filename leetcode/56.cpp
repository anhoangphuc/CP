class Solution {
public:
    const int BASE = 1e4 + 3;
    vector<int> mp = vector<int>(BASE);
    set<int> s;
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res = {};
        for (auto interval : intervals) {
            if (interval[1] > interval[0]) {
                mp[interval[1]] -= 1;
                mp[interval[0]] += 1;
            } else {
                s.insert(interval[0]);
            }
        }

        for (auto i = 1; i < BASE; i++) {
            mp[i] = mp[i - 1] + mp[i];
        }
        int low(-1), high(-1);
        for (auto i = 0; i < BASE; i++) {
            if (mp[i] > 0) {
                if (low == -1) {
                    low = i;
                    high = i;
                } else {
                    high = i;
                }
            } else {
                if (low != -1) {
                    res.push_back({low, high + 1});
                    low = -1;
                    high = -1;
                }
            }
        }
        for (auto x : s) {
            if (mp[x] == 0 && (x == 0 || mp[x - 1] == 0)) {
                res.push_back({x, x});
            }
        }
        return res;
    }
};
