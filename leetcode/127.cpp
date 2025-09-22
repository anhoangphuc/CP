#include <string>
#include <vector>
#include <map>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
    public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool n = wordList.size();
        int endPos = 5003;

        // Build edges
        map<int, vector<int>> edges;
        // We assume beginWord is n
        edges[n] = {};
        for (auto i = 0; i < n; i++) {
            if (isAdj(beginWord, wordList[i])) {
                edges[n].push_back(i);
            }
            if (endWord == wordList[i]) {
                endPos = i;
            }
            for (auto j = 0; j < i; j++) {
                if (isAdj(wordList[i], wordList[j])) {
                    if (edges.contains(i)) {
                        edges[i].push_back(j);
                    } else {
                        edges[i] = {j};
                    }

                    if (edges.contains(j)) {
                        edges[j].push_back(i);
                    } else {
                        edges[j] = {i};
                    }
                }
            }
        }

        queue<int> q;
        vector<int> d(n + 1);
        d[n] = 1;
        q.push(n);
        while (!q.empty()) {
            auto u = q.front();
            if (u == endPos) {
                return d[u];
            }
            for (auto v : edges[u]) {
                if (d[v] != 0)
                    continue;
                d[v] = d[u] + 1;
                q.push(v);
            }
            q.pop();
        }
        return 0;
    }

    bool isAdj(string s1, string s2) {
        int diff = 0;
        auto l = ssize(s1);
        for (auto i = 0; i < l; i++) {
            diff += (s1[i] != s2[i]);
        }
        return diff == 1;
    }
};

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

    Solution s = Solution();
    int res = s.ladderLength(beginWord, endWord, wordList);
    cout << res;
}
