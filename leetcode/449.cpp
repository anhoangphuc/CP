#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Codec {
	public:
		string serialize(TreeNode* root) {
			if (root == NULL) return "";
			string r = to_string(root->val);
			string left = serialize(root->left);
			string right = serialize(root->right);
			if (left == "") r = r + "," + left;
			if (right == "") r = r + "," + right;
			return r;
		}

		TreeNode* deserialize(string data) {
			if (data == "") return NULL;
			string sub = string(data.begin(), data.begin() + data.find(","));
			data.erase(data.begin(), data.begin() + data.find(",") + 1);
			int rootVal = stoi(sub);
			TreeNode* r = new TreeNode(rootVal);
			int previousComma = -1;
			int currentComma;
			int pivotComma = -2;
			while (true) {
				currentComma = data.find(",", previousComma + 1);
				if (currentComma == string::npos) break;
				auto sub = string(data.begin() + previousComma + 1, data.begin() + currentComma);
				auto val = stoi(sub);
				if (val > rootVal) {
					pivotComma = previousComma;
					break;
				}
			}
			if (pivotComma == -1) {
				r->left = NULL;
				r->right = deserialize(string(data.begin(), data.end()));
			}	else if (pivotComma == -2) {
				r->left = deserialize(string(data.begin(), data.end()));
				r->right = NULL;
			} else {
				r->left = deserialize(string(data.begin(), data.begin() + pivotComma));
				r->right = deserialize(string(data.begin() + pivotComma + 1, data.end()));
			}
			return r;
		}
};

int main() {
	return 0;
}

