#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int i = -1;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == ' ') {
                reverse(s.begin() + i + 1, s.begin() + j);
                i = j;
            }
        }
        reverse(s.begin() + i + 1, s.end());    
    }
};
