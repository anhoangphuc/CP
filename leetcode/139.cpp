#include <string>
#include <map>
#include <vector>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, bool> m;
        for (auto word : wordDict) {
            m[word] = true;
        }
        map<int, bool> r;
        r[0] = true;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j >= 0; j--) {
                string w = string(s.begin() + j, s.begin() + i + 1);
                //cout << i << " " << j << " " << w << endl;
                if (m[w] == true && r[j]) {
                    //cout << "TRUE HERE" << endl;
                    r[i + 1] = true;
                    break;
                }
            }
        }
        return r[s.size()];
    }
};
