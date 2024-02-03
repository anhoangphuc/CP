class Solution {
public:
    stack<int> nums;
    stack<char> op;
    int calculate(string s) {
        int i = 0;
        while (i < s.size()) {
            cout << i << " " << s[i] << endl;
            if (s[i] >= '0' && s[i] <= '9') {
                int j = i;
                int num(0);
                while (j < s.size() && s[j] >= '0' && s[j] <= '9') {
                    num = num * 10 + (s[j] - '0');
                    j += 1;
                }
                i = j;
                cout << "JUMP here " << (op.empty() ? ' ' : op.top()) << endl;
                if (!op.empty() && (op.top() == '/' || op.top() == '*')) {
                    char operation = op.top();
                    op.pop();
                    int previousNum = nums.top();
                    nums.pop();
                    cout << "NUM " << num << " " << previousNum << " "
                         << operation << endl;
                    if (operation == '/')
                        nums.push(previousNum / num);
                    else
                        nums.push(previousNum * num);
                } else {
                    nums.push(num);
                }
            } else if (s[i] == '*' || s[i] == '/') {
                op.push(s[i]);
                i += 1;
            } else if (s[i] == '+' || s[i] == '-') {
                if (!op.empty()) {
                    char operation = op.top();
                    op.pop();
                    auto curNum = nums.top();
                    nums.pop();
                    auto previousNum = nums.top();
                    nums.pop();
                    if (operation == '+')
                        nums.push(curNum + previousNum);
                    else
                        nums.push(previousNum - curNum);
                }
                op.push(s[i]);
                i += 1;
            } else {
                i += 1;
            }
        }
        // Final stack will have at most 2 elements
        if (nums.size() == 2) {
            int curNum = nums.top();
            nums.pop();
            int previousNum = nums.top();
            nums.pop();
            int operation = op.top();
            op.pop();
            if (operation == '+')
                nums.push(previousNum + curNum);
            else
                nums.push(previousNum - curNum);
        }

        return nums.top();
    }
};
