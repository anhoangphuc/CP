#include <vector>
#include <map>

using namespace std;

class Solution {
    public:
        int distributeCandies(vector<int>& candyType) {
            map<int, bool> isExists;

            int candyNumber = ssize(candyType);
            int typeNumber = 0;

            for (auto type: candyType) {
                if (!isExists[type]) {
                    typeNumber += 1;
                }
                isExists[type] = true;
            }

            return min(candyNumber / 2, typeNumber);
        }
};

int main() {
}
