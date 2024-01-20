class Solution {
public:
    map<string, int> mp;
    int romanToInt(string s) {
        mp["I"] = 1;
        mp["V"] = 5;
        mp["X"] = 10;
        mp["L"] = 50;
        mp["C"] = 100;
        mp["D"] = 500;
        mp["M"] = 1000;
        mp["IV"] = 4;
        mp["IX"] = 9;
        mp["XL"] = 40;
        mp["XC"] = 90;
        mp["CD"] = 400;
        mp["CM"] = 900;
        int i = 0;
        int res(0);
        while (i < s.size()) {
            string vv = string(1, s[i]) + (i < s.size() - 1 ? string(1, s[i + 1]) : "");
            string v = string(1, s[i]);
            if (mp.find(vv) != mp.end()) {
                res += mp[vv];
                i += 2;
            } else {
                res += mp[v];
                i += 1;
            }
        }  
        return res;  
    }
};
