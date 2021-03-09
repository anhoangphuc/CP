#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (auto i = a; i <= b; i++)
#define repr(i, a, b) for (auto i = a; i >= b; i--)
#define ll long long

const int oo = 1e9 + 7;

int n, contestTime, A, B, C, t0;
priority_queue<int, vector<int>, greater<int>> pq;
//----------------------------------------
void openf() {
    cin >> n >> contestTime;
    cin >> A >> B >> C >> t0; 
 }
//----------------------------------------
void process() {
    pq.push(t0);
    int temp = t0;
    rep(i, 1, n - 1) {
        temp = (((ll)A * temp + B) % C) + 1;
        pq.push(temp);
    }

    int maxNumber = 0, penaltyCounter = 0, totalTime = 0;
    while (!pq.empty()) {
        if (totalTime <= contestTime - pq.top()) {
            totalTime += pq.top();
            maxNumber += 1;
            penaltyCounter = (penaltyCounter + totalTime) % oo;
        }
        pq.pop();
    }

    cout << maxNumber << " " << penaltyCounter;
}
//----------------------------------------
int main() {
    //freopen("test.inp", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /**
    int testCase;
    cin >> testCase;
    rep(test, 1, testCase) {
        openf();
        process();
    } */

    openf();
    process();
}