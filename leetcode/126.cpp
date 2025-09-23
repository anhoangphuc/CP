#include <string>
#include <vector>
#include <queue>
#include <list>
#include <map>
#include <iostream>

using namespace std;

class Solution {
    public:
        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
            auto L = ssize(beginWord);
            map<string, vector<string>> edges;
            bool isBeginIn = false;
            bool isEndIn = false;

            // Build edges
            for (auto word: wordList) {
                isBeginIn = isBeginIn || (beginWord == word);
                isEndIn = isEndIn || (endWord == word);
                for (auto i = 0; i < L; i++) {
                    auto newWord = transform(word, i);
                    if (edges.contains(newWord)) {
                        edges[newWord].push_back(word);
                    } else {
                        edges[newWord] = { word };
                    }
                }
            }

            if (!isEndIn) {
                return {};
            }
            if (!isBeginIn) {
                for (auto i = 0; i < L; i++) {
                    string newWord = transform(beginWord, i);
                    if (edges.contains(newWord)) {
                        edges[newWord].push_back(beginWord);
                    } else {
                        edges[newWord] = { beginWord };
                    }
                }
            }

            map<string, int> d;
            queue<string> q;
            d[beginWord] = 1;
            q.push(beginWord);
            while (!q.empty()) {
                auto word = q.front();
                q.pop();
                for (auto i = 0; i < L; i++) {
                    string newWord = transform(word, i);
                    for (auto edgeWord: edges[newWord]) {
                        if (d[edgeWord] != 0) continue;
                        d[edgeWord] = d[word] + 1;
                        q.push(edgeWord);
                    }
                }
            }
            vector<vector<string>> res;
            traverse(edges, d, res, {}, endWord, beginWord);
            return res; 
        }

        void traverse(map<string, vector<string>>& edges, map<string, int>& d, vector<vector<string>>& res, list<string> currentRes, string currentWord, string beginWord) {
            currentRes.push_front(currentWord);
            if (currentWord == beginWord) {
                vector<string> tmp(currentRes.begin(), currentRes.end());
                res.push_back(tmp);
                currentRes.pop_front();
                return;
            }
            
            auto L = ssize(currentWord);
            for (auto i = 0; i < L; i++) {
                auto newWord = transform(currentWord, i);
                for (auto edgeWord: edges[newWord]) {
                    if (d[edgeWord] + 1 == d[currentWord]) {
                        traverse(edges, d, res, currentRes, edgeWord, beginWord);
                    }
                }
            }
            currentRes.pop_front();
        }

        string transform(string s, int pos) {
            return string(s.begin(), s.begin() + pos) + "*" + string(s.begin() + pos + 1, s.end());
        }
};

int main() {
    Solution s = Solution();
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = { "hot","dot","dog","lot","log","cog" };
    auto res = s.findLadders(beginWord, endWord, wordList);

    for (auto r: res) {
        for (auto w: r) {
            cout << w << " ";
        }

        cout << endl;
    }
}
