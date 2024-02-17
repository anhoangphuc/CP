class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> v;
        for (auto timePoint : timePoints) {
            auto x = stoi(timePoint.substr(0, 2));
            auto y = stoi(timePoint.substr(3, 2));
            v.push_back(x * 60 + y);
        }
        auto t = 60 * 24;
        sort(v.begin(), v.end());
        auto res = min(v[1] - v[0], t - (v[1] - v[0]));
        for (auto i = 2; i < v.size(); i++) {
            res = min(res, min(v[i] - v[i - 1], t - (v[i] - v[i - 1])));
        }
        res = min(res, min(v.back() - v.front(), t - (v.back() - v.front())));
        return res;
    }
};
