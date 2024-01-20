class Solution {
public:
    string reverseWords(string s) {
        string res("");
        string cur("");
        s += ' ';
        for (auto x : s) {
            if (x == ' ') {
                if (cur != "") {
                    if (res == "") {
                        res = cur;
                    } else {
                        res = cur + " " + res;
                    }
                }
                cur = "";
            } else {
                cur = cur + x;
            }
        }
        return res;
    }
};
