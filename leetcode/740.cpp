#include <vector>

using namespace std;

class Solution {
    public:
    const int MAX_VALUE = 1e4 + 4;
    int deleteAndEarn(vector<int>& nums) {
        vector<int> d(MAX_VALUE);
        for (auto num: nums) {
            d[num] += num;
        }

        int res = 0;
        vector<int> v(MAX_VALUE);
        v[1] = d[1];
        res = v[1];
        for (auto i = 2; i < MAX_VALUE - 1; i++) {
            v[i] = max(d[i] + v[i - 2], v[i - 1]);
            res = max(res, v[i]);
        }
        return res;
    }
};

int main() {

}
