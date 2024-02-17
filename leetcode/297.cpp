#include <iostream>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Code {
	public:
	string serialize(TreeNode* root) {
		if (root == NULL) return "()";
		string res = "(";	
		res += to_string(root->val);
		res += serialize(root->left);
		res += serialize(root->right);
		res += ")";
		return res;
	}
	TreeNode* deserialize(string data) {
		if (data == "()") return NULL;
		auto l = data.size();
		// Get substr in range [1..-1]
		data = data.substr(1, l - 2);
		int firstOpen = -1;
		int firstClose = -1;
		auto cnt = 0;
		for (auto i = 0; i < data.size(); i++) {
			auto ch = data[i];
			if (ch == '(' || ch == ')') {
				if (ch == '(') cnt += 1;
				else cnt -= 1;
				if (cnt == 1 && firstOpen == -1) {
					firstOpen = i;	
				}
				if (cnt == 0 && firstClose == -1) {
					firstClose = i;
					break;
				}
			}
		}
		auto numberPart = data.substr(0, firstOpen);
		auto leftPart = data.substr(firstOpen, firstClose - firstOpen + 1);
		auto rightPart = data.substr(firstClose + 1, data.size() - 1 - firstClose); 
		auto res = new TreeNode(stoi(numberPart));
		res->left = deserialize(leftPart);
		res->right = deserialize(rightPart);
		return res;
	}
};

int main() {
	return 0;
}
