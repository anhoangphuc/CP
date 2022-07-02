#include <string>
#include <algorithm>

using namespace std;

class Solution {
    public:
        string countAndSay(int n) {
            if (n == 1) return "1";
            string previousSay = countAndSay(n - 1);
            auto firstIter = previousSay.begin();
            string res = "";
            while (firstIter != previousSay.end()) {
                auto differentCharacterIter = find_if(firstIter, previousSay.end(), [firstIter](char x) { return x != *firstIter; });
                string substr;
                copy(firstIter, differentCharacterIter, back_inserter(substr));
                res = res + to_string(substr.length()) + substr[0];
                firstIter = differentCharacterIter;
            }
            return res;
        }
};

