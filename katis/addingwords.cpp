#include <bits/stdc++.h>
using namespace std;

map<string, int> stringToInt;
map<int, string> intToString;
const int oo = -1e9;

//----------------------------------------
int main() {
    string s, variable;
    int value;
    //freopen("test.inp", "r", stdin);

    while (cin >> s) {
        if (s == "clear") {
            stringToInt.clear();
            intToString.clear();
        }
        else if (s == "def") {
            cin >> variable >> value;
            if (stringToInt.find(variable) != stringToInt.end()) {
                intToString.erase(stringToInt[variable]);
            }
            stringToInt[variable] = value;
            intToString[value] = variable;
        }
        else {
            int temp = 0, currentSign = 1;
            string res = "";
            while (cin >> variable) {
                res += (variable +  " ");
                if (variable == "+" || variable == "-") { 
                    currentSign = variable == "+" ? 1: -1;
                }
                else if (variable == "=") {
                    if (intToString.find(temp) == intToString.end())
                        res += "unknown\n";
                    else res += intToString[temp] + "\n";
                    cout << res;
                    break;
                }
                else {
                    if (temp == oo) continue;
                    if (stringToInt.find(variable) == stringToInt.end()) {
                        temp = oo;
                        continue;
                    } else {
                        temp += currentSign * stringToInt[variable];
                    }
                } 
            }
        }
    }
}