#include <bits/stdc++.h>
using namespace std;

#define fori(i, a, b, t) for (int i = a; i <= b; i += t)
#define forr(i, a, b, t) for (int i = a; i >= b; i += t)

const int NMAX = 107;

char a[NMAX][NMAX];
string originalMessage;

//----------------------------------------
void openf() {
    cin >> originalMessage; 
}
//----------------------------------------
void process() {
    // find padded message length
    int messageLength = originalMessage.length();
    int paddedSqare = round(sqrt(messageLength));
    if (paddedSqare * paddedSqare < messageLength)
        paddedSqare += 1;
    int paddedMessageLength = paddedSqare * paddedSqare;

    // push padded message into table
    fori(i, 1, paddedMessageLength - messageLength, 1) 
        originalMessage += '*';
    
    int currentPosition = 0;
    fori(i, 1, paddedSqare, 1)
        fori(j, 1, paddedSqare, 1) 
            a[i][j] = originalMessage[currentPosition++];

    //write encrypted message
    fori(j, 1, paddedSqare, 1)
        forr(i, paddedSqare, 1, -1) 
            if (a[i][j] != '*') cout << a[i][j];
}
//----------------------------------------
int main() {
    int testCase;
    cin >> testCase;
    while (testCase--) {
        openf();
        process();
        if (testCase > 0)
            cout << endl;
    }
}