#include <string>
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;


typedef vector<int> BigNum;

class Solution {
    public:
        string multiply(string num1, string num2) {
            BigNum a, b, res;
            for (auto it = num1.rbegin(); it != num1.rend(); it++) {
                a.push_back(*it - '0');
            }

            for (auto it = num2.rbegin(); it != num2.rend(); it++) {
                b.push_back(*it - '0');
            }
            
            for (auto i = 0; i < a.size(); i++) {
                BigNum tmp = mul(b, a[i]);
                reverse(tmp.begin(), tmp.end());
                for (int j = 0; j < i; j++)
                    tmp.push_back(0);
                reverse(tmp.begin(), tmp.end());
                res = add(res, tmp);
            }
            string resString = accumulate(res.begin(), res.end(), string {},
                    [](string g, int x) { return g + to_string(x); });
            reverse(resString.begin(), resString.end());
            auto it = find_if_not(resString.begin(), resString.end(), [](char x) { return x == '0'; });
            if (it == resString.end()) resString = "0"; else resString = string(it, resString.end());
            return resString;
        }

    private:
        BigNum add(BigNum a, BigNum b) {
            BigNum res;
            int carry = 0, tmp = 0;
            while (a.size() < b.size()) a.push_back(0);
            while (b.size() < a.size()) b.push_back(0);
            for (int i = 0; i < a.size(); i++) {
                tmp = a[i] + b[i] + carry;
                res.push_back(tmp % 10);
                carry = tmp / 10;
            }
            if (carry > 0) res.push_back(carry);
            return res;
        }

        BigNum mul(BigNum a, int b) {
            BigNum res;
            int carry = 0, tmp = 0;
            for (int i = 0; i < a.size(); i++) {
                tmp = b * a[i] + carry;
                res.push_back(tmp % 10);
                carry = tmp / 10;
            }
            if (carry > 0) res.push_back(carry);
            return res;
        }
};

int main() {
    Solution a = Solution();
    string res = a.multiply("123", "456");
    cout << res;
}
