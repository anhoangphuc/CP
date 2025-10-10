#include <vector>
#include <map>

using namespace std;

class Solution {
    public:
        int mostFrequentEven(vector<int>& nums) {
            int res = -1;
            map<int, int> d;
            for (auto num: nums) {
                if (num % 2 == 1) continue;
                d[num] += 1;
                if (res == -1) {
                    res = num;
                } else if (d[num] > d[res] || (d[num] == d[res] && num < res)) {
                    res = num;
                }
            }
            return res;
        }
};

int main() {

}
