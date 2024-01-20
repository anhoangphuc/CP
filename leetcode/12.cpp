class Solution {
public:
    map<int, string> mp;
    string intToRoman(int num) {
        mp[1] = "I";
        mp[5] = "V";
        mp[10] = "X";
        mp[50] = "L";
        mp[100] = "C";
        mp[500] = "D";
        mp[1000] = "M";
        mp[4] = "IV";
        mp[9] = "IX";
        mp[40] = "XL";
        mp[90] = "XC";
        mp[400] = "CD";
        mp[900] = "CM";
        string res("");

        while (num > 0) {
            int val = 0;
            for (auto p : mp) {
                if (p.first <= num) {
                    val = p.first;
                }
            }
            num -= val;
            res += mp[val];
        }
        return res;
    }
};
