#include <bits/stdc++.h>
using namespace std;

map<string, int> eventToInt;
stack<string> events; 
const string ERROR = "Plot Error";

//----------------------------------------
int main() {
    // freopen("test.inp", "r", stdin);
    string type, event;
    int r, n;
    cin >> n;
    while (n--) {
        cin >> type;
        if (type == "E") {
            cin >> event;
            events.push(event);
            eventToInt[event] = events.size();
        }
        else if(type == "D") {
            cin >> r;
            while (r--) {
                event = events.top();
                eventToInt.erase(event);
                events.pop();
            }
        }
        else {
            cin >> r;
            string res = "";
            int ma = 0, mi = 1e6;
            while (r--) {
                cin >> event;
                if (res == ERROR) continue;
                if (event[0] != '!') {
                    if (eventToInt.find(event) == eventToInt.end())  //In scenario, but not real
                        res = ERROR;
                    else ma = max(ma, eventToInt[event]);
                } else {
                    event = event.substr(1, event.length() - 1);
                    if (eventToInt.find(event) != eventToInt.end()) //Not in scenario, in real
                        mi = min(mi, eventToInt[event]);
                }
            }

            if (res != ERROR)
                if (mi == 1e6) res = "Yes";
                else {
                    if (mi <= ma) res = "Plot Error";
                    else res = to_string(events.size() - mi + 1) + " Just A Dream";
                }
            cout << res << endl; 
        }
    }
}