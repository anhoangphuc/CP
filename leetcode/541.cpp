#include <string>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0;
        while (i < s.size()) {
            int j = min(i + 2 * k - 1, int(s.size()) - 1);
            int r = min(i + k - 1, j);
            reverse(s.begin() + i, s.begin() + r + 1);
            i = i + 2 * k;
        }
        return s;
    }
};
