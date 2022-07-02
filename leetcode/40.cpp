#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> currentCombination;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        tryCombination(candidates, 0, 0, target);
        return res;
    }

    void tryCombination(vector<int>& candidates, int currentPos, int currentSum, int target) {
        if (currentSum == target) {
            res.push_back(currentCombination);
            return;
        }

        for (int i = currentPos; i < candidates.size(); i++) {
            if (i > currentPos && candidates[i] == candidates[i - 1]) continue;
            if (currentSum + candidates[i] > target) continue;
            currentCombination.push_back(candidates[i]);
            tryCombination(candidates, i + 1, currentSum + candidates[i], target);
            currentCombination.pop_back();
        }
    }
};
