#define fori(i, a, b, c) for (int i=a; i <= b; i += c)
#include <bits/stdc++.h>
using namespace std;


//----------------------------------------
int stringToSecond(string timeString) {
    int res = 0;
    res = stoi(timeString.substr(0, 2)) * 3600;
    res += stoi(timeString.substr(3, 2)) * 60;
    res += stoi(timeString.substr(6, 2));
    return res; 
}
//----------------------------------------
string pad(string temp) {
    if (temp.length() < 2) {
        temp = '0' + temp;
    }
    return temp;
}
//----------------------------------------
string secondToString(int timeSecond) {
    string hour = to_string(timeSecond / 3600);
    timeSecond %= 3600;
    hour = pad(hour);

    string minute = to_string(timeSecond / 60);
    timeSecond %= 60;
    minute = pad(minute);

    string second = to_string(timeSecond);
    second = pad(second);

    return hour + ":" + minute + ":" + second;
}
//----------------------------------------
int main() {
    string timeXString, timeYString; 
    cin >> timeXString; 
    cin >> timeYString;
    int timeXInSecond = stringToSecond(timeXString);
    int timeYInSecond = stringToSecond(timeYString);
    int differenceInSecond = timeYInSecond - timeXInSecond;
    if (differenceInSecond <= 0) 
        differenceInSecond += 24 * 3600;
    cout << secondToString(differenceInSecond);
}