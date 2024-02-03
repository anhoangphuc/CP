class Solution {
public:
    stack<int> nums;
    int calculate(string s) {
	int i = 0;
	int num(0);
	char sign('+');
	while (i < s.size()) {
		if (s[i] >= '0' && s[i] <= '9') {
			num = num * 10 + (s[i] - '0');
		}
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i + 1 == s.size()) {
			if (sign == '+') {
				nums.push(num);
			} else if (sign == '-') {
				nums.push(-num);
			} else if (sign == '/') {
				int previousNum = nums.top();
				nums.pop();
				nums.push(previousNum / num);
			} else if (sign == '*') {
				int previousNum = nums.top();
				nums.pop();
				nums.push(previousNum * num);
			}
			sign = s[i];
			num = 0;
		}
		i += 1;
	}	
	int res(0);	
	while (!nums.empty()) {
		num = nums.top();
		nums.pop();
		res += num
	}
	return res;
    }
};
