#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() == 0) return word2.size();
        if (word2.size() == 0) return word1.size();
        vector<vector<int>> v(word1.size() + 1, vector<int>(word2.size() + 1));
        for (int i = 0; i <= word1.size(); i++)
            v[i][0] = i;
        for (int j = 0; j <= word2.size(); j++)
            v[0][j] = j;
        for (int i = 1; i <= word1.size(); i++)
            for (int j = 1; j <= word2.size(); j++) {
                v[i][j] = min(v[i - 1][j], v[i][j - 1]) + 1;
                v[i][j] = min(v[i][j], v[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]));
            }
        return v[word1.size()][word2.size()];
    }
};
