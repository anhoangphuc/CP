class Solution {
public:
    map<char, int> m;
    vector<string> generatePalindromes(string s) {
        vector<string> res = {};
        for (auto x: s) {
            m[x] = m[x] + 1;
        }
        auto cnt = 0;
        for (auto ch = 'a'; ch <= 'z'; ch++) {
            cnt += m[ch] % 2;
        }
        if (cnt > 1) return {};
        string tmp = "";
        for (auto ch = 'a'; ch <= 'z'; ch++) {
            if (m[ch] % 2 == 1) {
                tmp = tmp + ch;
                break;
            }
        }
        generateHelper(tmp, res, s.size());
        return res;
    }

    void generateHelper(string tmp, vector<string>& res, int len) {
        if (tmp.size() == len) {
            res.push_back(tmp);
            return;
        }
        for (auto ch = 'a'; ch <= 'z'; ch++) {
            if (m[ch] > 1) {
                m[ch] -= 2;
                generateHelper(ch + tmp + ch, res, len);
                m[ch] += 2;
            }
        }
    }
};
