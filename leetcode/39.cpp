#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        tryValue(candidates, target, 0, 0, {});
        return res;
    }

    void tryValue(vector<int>& candidates, int target, int position, int currentSum, vector<int> currentCombination) {
        if (position == candidates.size()) {
            if (target == currentSum) res.push_back(currentCombination);
            return;
        }
        int rep = (target - currentSum) / candidates[position];
        for (int i = 0; i <= rep; i++) {
            vector<int> newValue(i, candidates[position]);
            vector<int> newCombination(currentCombination);
            newCombination.insert(newCombination.end(), newValue.begin(), newValue.end());
            tryValue(candidates, target, position + 1, currentSum + candidates[position] * i, newCombination);
        }
    }
};

int main() {
    Solution a = Solution();
    vector<int> v = { 2, 3, 6, 7 };
    auto r = a.combinationSum(v, 8);
    for (auto x: r) {
        for (auto y: x) cout << y << " ";
        cout << endl;
    }
}
