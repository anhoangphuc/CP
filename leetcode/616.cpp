#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Solution {
    public:
        string addBoldTag(string s, vector<string>& words) {
            auto L = ssize(s);
            set<string> exists;
            vector<int> d(L + 1);
            for (auto word: words) {
                exists.insert(word);
            }

            for (auto i = 0; i < L; i++) {
                string sub("");
                for (auto j = i; j < L; j++) {
                    sub += s[j];
                    if (exists.contains(sub)) {
                        d[i] += 1;
                        d[j + 1] -= 1;
                    }
                }
            }

            
            for (auto i = 1; i < L; i++) {
                d[i] = d[i - 1] + d[i];
            }

            string res("");
            bool isOpen = false;
            for (auto i = 0; i <= L; i++) {
                // In bracket
                if (d[i] > 0) {
                    // If not open before, add open bracket
                    if (!isOpen) {
                        res += "<b>";
                    }
                    isOpen = true;
                } else {  // Not in bracket
                    if (isOpen) {
                        res += "</b>";
                    }
                    isOpen = false;
                }
                if (i < L) {
                    res += s[i];
                }
            }
            return res;
        }
};

int main() {
    string s = "abcxyz123";
    vector<string> words = { "abc", "123" };

    Solution sol = Solution();
    auto res = sol.addBoldTag(s, words);
    cout << res;
}
