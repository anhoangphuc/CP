#include <string>

using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            string newS("");
            for (auto x:s) {
                x = tolower(x);
                if ((x >= 'a' && x <= 'z') || (x >= '0' && x <= '9'))
                    newS += x;
            }
            int i = 0;
            int j = newS.size() - 1;
            while (i < j) {
                if (newS[i] != newS[j]) return false;
                i++;
                j--;
            }
            return true;
        }
};
int main() {

}
