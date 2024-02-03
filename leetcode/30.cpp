class Solution {
public:
    map<string, int> required;
    map<string, int> cur;
    vector<int> findSubstring(string s, vector<string>& words) {
        int differWord(0);
        for (auto word : words) {
            if (required.find(word) == required.end()) {
                required[word] = 1;
            } else {
                required[word] += 1;
            }
            differWord += (required[word] == 1);
        }
        vector<int> res = {};
        for (int i = 0; i < words[0].size(); i++) {
            findHelper(s.substr(i), words, res, differWord, i);
        }
        return res;
    }

    void findHelper(string s, vector<string>& words, vector<int>& res, int differWord, int startIndex) {
        cur = {};
        int wordLen = words[0].size();
        int substringLen = words.size() * wordLen;
        int i = wordLen - 1;
        int j(-1);
        int enoughWord = 0;
        while (i < s.size()) {
            auto ss = s.substr(i - wordLen + 1, wordLen);
            if (cur.find(ss) == cur.end()) {
                cur[ss] = 1;
            } else {
                cur[ss] += 1;
            }
            if (required.find(ss) != required.end() &&
                required[ss] == cur[ss]) {
                enoughWord += 1;
            }
            if (i - j > substringLen) {
                auto ss = s.substr(j + 1, wordLen);
                if (cur.find(ss) != cur.end()) {
                    if (required.find(ss) != required.end() &&
                        required[ss] == cur[ss])
                        enoughWord -= 1;
                    cur[ss] -= 1;
                }
                j = j + wordLen;
            }
            if (enoughWord == differWord) {
                res.push_back(j + 1 + startIndex);
            }
            i += wordLen;
        }
    }
};
