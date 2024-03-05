#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int cnt = 0;
        vector<int> m(30);
        int j = 0;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            m[s[i] - 'a'] += 1;
            if (m[s[i] - 'a'] == 2)
                cnt += 1;
            if (i - j + 1 > k) {
                m[s[j] - 'a'] -= 1;
                if (m[s[j] - 'a'] == 1)
                    cnt -= 1;
                j += 1;
            }
            if (i - j + 1 == k && cnt == 0)
                res += 1;
        }
        return res;
    }
};
