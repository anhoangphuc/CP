#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <numeric>

using namespace std;


class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            map<string, int> ind;
            vector<vector<string>> res;
            for (auto str: strs) {
                auto tmp = str;
                sort(tmp.begin(), tmp.end());
                if (ind.find(tmp) == ind.end()) {
                    res.push_back({});
                    ind[tmp] = res.size() - 1;
                }
                res[ind[tmp]].push_back(str);
            }
            return res;
        }
};

int main() {
    Solution a = Solution();
    vector<string> strs { "abc", "cba", "aa" };
    auto res = a.groupAnagrams(strs);
    for (auto x: res) {
        for (auto y: x) {
            cout << y << " ";
        }

        cout << endl;
    }
}
