#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
	int height = 0;
	auto cur = root;
	while (cur != NULL) {
		// Traverse right to assign edge case
		height += 1;
		cur->next  = NULL;
		cur = cur->right;
	}
	for (int i = 1; i <= height; i++) {
		Node* pre = NULL;
		connectHelper(root, i, pre);
	}
	return root;
    }
    void connectHelper(Node* root, int height, Node*& pre) {
	if (height == 1) {
		if (pre != NULL) pre->next = root;
		pre = root;
		return;
	}	
	connectHelper(root -> left, height - 1, pre);
	connectHelper(root -> right, height - 1, pre);
    }
};

int main() {
	return 0;
}
