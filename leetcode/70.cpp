class Solution {
public:
    const int MAX_V = 50;
    vector<long long int> v;
    int climbStairs(int n) {
        v.resize(MAX_V);
        v[0] = 1;
        v[1] = 1;
        for (auto i = 2; i <= n; i++) {
            v[i] = v[i - 1] + v[i - 2];
        }
        return v[n];
    }
};
