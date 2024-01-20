class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            string res("");
            for (int i = 0; i < strs[0].size(); i++) {
                int c = strs[0][i];
                for (auto str: strs) {
                    if (i >= str.size() || str[i] != c) {
                        return res;
                    }
                }
                res += c;
            }
            return res;
        }
}
