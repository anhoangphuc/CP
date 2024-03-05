#include <string>
using namespace std;
class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string res = "";
        while (a != 0 && b != 0) {
            if (a > b) {
                res = res + "aa" + "b";
                a -= 2;
                b -= 1;
            } else if (a < b) {
                res = res + "bb" + "a";
                a -= 1;
                b -= 2;
            } else {
                // a == b
                if (res.empty() || res.back() == 'a') {
                    for (int i = 1; i <= a; i++) {
                        res = res + "ba";
                    }
                } else {
                    for (int i = 1; i <= a; i++) {
                        res = res + "ab";
                    }
                }
                a = 0;
                b = 0;
            }
        }
        //cout << "RES " << res << endl;
        if (a > 0)
            res = res + string(a, 'a');
        if (b > 0)
            res = res + string(b, 'b');
        return res;
    }
};
