class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res {};
        vector<string> curs {};
        int cursSize = 0;
        for (auto word: words) {
            if (cursSize + word.size() + curs.size() > maxWidth) {
                string r("");
                if (curs.size() == 1) curs.push_back("");
                int spaceWidth = (maxWidth - cursSize) / (curs.size() - 1);
                int moreWidth = (maxWidth - cursSize) % (curs.size() - 1);
                for (int i = 0; i < curs.size(); i++) {
                    r += curs[i];
                    if (i < curs.size() - 1) {
                        r += string(spaceWidth, ' ');
                    }
                    if (moreWidth-- > 0) {
                        r += " ";
                    }
                }
                res.push_back(r);
                cursSize = 0;
                curs.clear();
                curs.push_back(word);
                cursSize = word.size();
            } else {
                curs.push_back(word);
                cursSize += word.size();
            }
        }
        string r("");
        for (int i = 0; i < curs.size(); i++) {
            r += curs[i];
            if (i != curs.size() - 1) r +=  " ";
        }
        r += string(maxWidth - r.size(), ' ');
        res.push_back(r);
        return res;
    }
};
