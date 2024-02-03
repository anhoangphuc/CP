class Solution {
public:
    stack<int> numbers;
    int calculate(string s) {
        int res(0);
        int i = 0;
        int sign = 1;
        while (i < s.size()) {
            if (s[i] >= '0' && s[i] <= '9') {
                int j = i;
                int num(0);
                while (j < s.size() && s[j] >= '0' && s[j] <= '9') {
                    num = num * 10 + (s[j] - '0');
                    j += 1;
                }
                i = j;
                res += num * sign;
            } else if (s[i] == '+') {
                sign = 1;
                i += 1;
            } else if (s[i] == '-') {
                sign = -1;
                i += 1;
            } else if (s[i] == '(') {
                numbers.push(res);
                numbers.push(sign);
                res = 0;
                sign = 1;
                i += 1;
            } else if (s[i] == ')') {
                sign = numbers.top();
                numbers.pop();
                int previousRes = numbers.top();
                numbers.pop();
                res = previousRes + res * sign;
                i += 1;
            } else {
                i += 1;
            }
        }
        return res;
    }
};
