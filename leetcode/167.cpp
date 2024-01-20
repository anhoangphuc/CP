#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
            vector<int> res {};
            int j = numbers.size() - 1;
            for (int i = 0; i < numbers.size(); i++) {
                while (numbers[i] + numbers[j] > target) {
                    j--;
                }
                if (numbers[i] + numbers[j] == target) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
            return res;
        }
}
