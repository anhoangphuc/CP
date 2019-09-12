#define fori(i, a, b, c) for (int i=a; i <= b; i += c)
#include <bits/stdc++.h>
using namespace std;

typedef pair<float, float> realNumber;
//----------------------------------------
float getModule(realNumber zn) {
    return sqrt(zn.first*zn.first + zn.second*zn.second);
}
//----------------------------------------
realNumber addRealNumber(realNumber firstNumber, realNumber secondNumber) {
    return realNumber(firstNumber.first + secondNumber.first,
                      firstNumber.second + secondNumber.second);
}
//----------------------------------------
realNumber doubleRealNumber(realNumber zn) {
    return realNumber(zn.first*zn.first - zn.second*zn.second, 2*zn.first*zn.second);
}
//----------------------------------------
string process(float realPortion, float imagPortion, int itera) {
    realNumber cValue = realNumber(realPortion, imagPortion);
    realNumber zn = realNumber(0, 0);
    do {
        if (getModule(zn) > 2) return "OUT";
        zn = addRealNumber(cValue, doubleRealNumber(zn));
    }
    while (itera-- > 0);
    return "IN";
}
//----------------------------------------
int main() {
    float realPortion, imagPortion;
    int itera, testCase = 0;
    while (cin >> realPortion >> imagPortion >> itera) {
        cout << "Case " << (++testCase) << ": " << process(realPortion, imagPortion, itera) << endl;
    }
}