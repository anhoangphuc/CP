#include <iostream>
#include <string>
#include <map>

using ll = long long;

using namespace std;

class Solution {
    public:
        string fractionToDecimal(int numerator, int denominator) {
            if (numerator == 0) {
                return "0";
            };

            string res("");
            // If one is positive, one is negative, prefix "-" before the result
            if (ll(numerator) * denominator < 0) {
                res = "-";
            }
            map<ll, int> pos;
            ll num = abs((ll(numerator)));
            ll den = abs(ll(denominator));

            res += to_string(num / den);
            num = num % den;

            string frac("");
            while (true) {
                if (num == 0) {
                    break;
                }
                if (!pos.contains(num)) {
                    pos[num] = ssize(frac);
                    frac += to_string((num * 10) / den);
                    num = (num * 10) % den;
                } else {
                    frac.insert(pos[num], "(");
                    frac += ")";
                    break;
                }
            }

            if (frac != "") {
                res += ("." + frac);
            }
            return res;
        }
};

int main() {
    Solution s = Solution();
    auto res = s.fractionToDecimal(4, 333);
    cout << res;
}
