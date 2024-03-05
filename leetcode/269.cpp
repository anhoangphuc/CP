#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string alienOrder(vector<string>& words) {
        vector<vector<bool>> m(30, vector<bool>(30));
        vector<bool> isValid(30);
        vector<int> d(30);
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < words.size() - 1; j++) {
                for (int k = j + 1; k < words.size(); k++) {
                    if (words[j].size() > i && words[k].size() > i &&
                        words[j][i] != words[k][i]) {
                        auto sub1 =
                            string(words[j].begin(), words[j].begin() + i);
                        auto sub2 =
                            string(words[k].begin(), words[k].begin() + i);
                        if (sub1 != sub2)
                            continue;
                        m[words[j][i] - 'a'][words[k][i] - 'a'] = true;
                    }
                }
            }
        }
        for (int i = 0; i < words.size() - 1; i++)
            for (int j = i + 1; j < words.size(); j++) {
                if ((words[i].find(words[j]) == 0) &&
                    (words[i].size() > words[j].size()))
                    return "";
            }
        int numberOfChar = 0;
        for (auto word : words) {
            for (auto x : word) {
                if (isValid[x - 'a'] == false)
                    numberOfChar += 1;
                isValid[x - 'a'] = true;
            }
        }
        for (auto i = 'a'; i <= 'z'; i++) {
            for (auto j = 'a'; j <= 'z'; j++) {
                if (i != j && m[i - 'a'][j - 'a']) {
                    d[j - 'a'] += 1;
                }
            }
        }

        queue<int> q;
        string res;
        for (auto i = 'a'; i <= 'z'; i++) {
            if (isValid[i - 'a'] && d[i - 'a'] == 0)
                q.push(i - 'a');
        }

        while (!q.empty()) {
            auto top = q.front();
            res = res + char(top + 'a');
            cout << "TOP " << char(top + 'a') << endl;
            cout << res << " " << endl;
            q.pop();
            for (auto i = 'a'; i <= 'z'; i++) {
                if (m[top][i - 'a']) {
                    d[i - 'a'] -= 1;
                    if (d[i - 'a'] == 0)
                        q.push(i - 'a');
                }
            }
        }
        if (res.size() == numberOfChar)
            return res;
        else
            return "";
    }
};
