#include <bits/stdc++.h>
using namespace std;

#define fori(i, a, b) for (int i = a; i <= b; i++)
int n, perArray[23];
string message; 
//----------------------------------------
void openf() {
    char ch;
    fori(i, 0, n - 1)
        cin >> perArray[i]; 
	cin.ignore();
    getline(cin, message);
}
//----------------------------------------
string encryptMessage(string subMessage) {
    string res = "";
    fori(i, 0, n - 1)
        res += subMessage[perArray[i] - 1];
    return res;
}
//----------------------------------------
void process() {
    while (message.length() % n != 0)
        message += ' ';
    cout << "'";
    int i = 0;
    while (i < message.length()) {
        string subMessage = message.substr(i, n);
        cout << encryptMessage(subMessage);
        i += n;
    }
    cout << "'" << endl;
}
//----------------------------------------
int main() {
    bool firstTime = true;
    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
    while (cin >> n) {
        if (n == 0) break;
        openf();
        process();
    }
}
