#include <vector>
#include <map>
#include <string>

using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> m;
        int cnt = 0;
        for (auto x : t) {
            m[x] += 1;
            if (m[x] == 1)
                cnt += 1;
        }
        int i = 0;
        string res = "";
        map<char, int> cur;
        for (int j = 0; j < s.size(); j++) {
            cur[s[j]] += 1;
            if (cur[s[j]] == m[s[j]])
                cnt -= 1;
            if (cnt == 0) {
                while (cur[s[i]] > m[s[i]]) {
                    cur[s[i]] -= 1;
                    i++;
                }
                if (res == "")
                    res = string(s.begin() + i, s.begin() + j + 1);
                else if (res.size() > j - i + 1)
                    res = string(s.begin() + i, s.begin() + j + 1);
            }
        }
        return res;
    }
};
