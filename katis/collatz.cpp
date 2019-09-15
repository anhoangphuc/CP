#include <bits/stdc++.h>
using namespace std;

#define fori(i, a, b) for (int i = a; i <= b; i++)
#define ll long long

map<ll, int> a;
map<ll, int> validValue;
//----------------------------------------
void process(int firstNum, int secondNum, int cnt) {
    ll tempFirstNum = firstNum;
    a[tempFirstNum] = 0;
    validValue[tempFirstNum] = cnt;
    fori(i, 1, 30000) {
        if ((tempFirstNum % 2 == 1 && tempFirstNum  > (10e18 - 1) / 3) || (tempFirstNum == 1))
            break;
        if (tempFirstNum % 2 == 0) 
            tempFirstNum /= 2;
        else 
            tempFirstNum = tempFirstNum * 3 + 1;
        if (validValue[tempFirstNum] != cnt) 
            a[tempFirstNum] = i;
        else
            break;
        validValue[tempFirstNum] = cnt;
    }

    ll tempSecondNum = secondNum;
    fori(i, 0, 30000) {
        if (validValue[tempSecondNum] == cnt) {
            cout << firstNum << " needs " << a[tempSecondNum] << " steps, ";
            cout << secondNum << " needs " << i << " steps, ";
            cout << "they meet at " << tempSecondNum;
            break;
        }
        if (tempSecondNum % 2 == 0) 
            tempSecondNum /= 2;
        else 
            tempSecondNum = tempSecondNum * 3 + 1;
    }
    cout << endl;
}
//----------------------------------------
int main() {
    int firstNum, secondNum;
    int cnt = 1;
    while (cin >> firstNum >> secondNum) {
        if (firstNum == 0) break;
        process(firstNum, secondNum, cnt++);
    }
}