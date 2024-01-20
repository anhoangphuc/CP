class Solution {
    public:
        int lengthOfLastWord(string s) {
            s += " ";
            int res(0);
            int cur(0);
            for (auto x: s) {
                if (x == " ") {
                    if (cur != 0) res = cur;
                    cur = 0;
                } else {
                    cur += 1;
                }
            }
            return res;
        }
}
