#include <string>
#include <iostream>

using namespace std;

class Solution {
    public:
        string addBinary(string a, string b) {
            string res("");
            auto ia = ssize(a) - 1;
            auto ib = ssize(b) - 1;
            bool carry = false;
            while (ia >= 0 || ib >= 0) {
                auto tmpa = ia >= 0 ? a[ia] : '0';
                auto tmpb = ib >= 0 ? b[ib] : '0';
                ia -= 1;
                ib -= 1; 

                if (tmpa == '0' && tmpb == '0') {
                    if (carry) {
                        res += '1';
                    } else {
                        res += '0';
                    }
                    carry = false;
                } else if (tmpa == '1' && tmpb == '1') {
                    if (carry) {
                        res += '1';
                    } else {
                        res += '0';
                    }
                    carry = true;
                } else {
                    if (carry) {
                        res += '0';
                    } else {
                        res += '1';
                    }
                }
            }
            if (carry) res += '1';
            reverse(res.begin(), res.end());
            return res;
        }
};

int main() {

}
