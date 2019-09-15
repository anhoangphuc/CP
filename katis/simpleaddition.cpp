#include <bits/stdc++.h>
using namespace std;

const int BASE = 1e9;
const int scs = 9;

typedef vector<int> BigInt;
//----------------------------------------
BigInt stringToBigInt(string s) {
    BigInt res;
    res.clear();

    int i = s.length() - 1;
    while (i >= 0) {
        int j = max(i - scs + 1, 0);
        res.push_back(stoi(s.substr(j, i - j + 1)));
        i = j - 1;
    }

    return res;
}
//----------------------------------------
void printBigInt(BigInt a) {
    for (auto x = a.rbegin(); x != a.rend(); x++) {
        if (x == a.rbegin()) cout << *x;
        else {
            string temp = to_string(*x);
            while (temp.length() < scs) temp = '0' + temp;
            cout << temp;
        }
    }
    cout << endl;
}
//----------------------------------------
BigInt addBigInt(BigInt firstNumber, BigInt secondNumber) {
    BigInt res;
    res.clear();

    int carry = 0;
    for (auto i = 0; i < max(firstNumber.size(), secondNumber.size()); i++) {
        auto val1 = i < firstNumber.size() ? firstNumber[i]:0;
        auto val2 = i < secondNumber.size() ? secondNumber[i]:0;
        auto tmp = (val1 + val2 + carry);
        res.push_back(tmp % BASE);
        carry = tmp / BASE;
    }

    return res;
}
//----------------------------------------
int main() {
    string s;
    cin >> s;
    auto firstNumber = stringToBigInt(s);
    cin >> s;
    auto secondNumber = stringToBigInt(s);

    printBigInt(addBigInt(firstNumber, secondNumber));
}