#include <iostream>
#include <map>

using namespace std;

class Node {
	public:
	int val;
	Node *next;
	Node *random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

class Solution {
	public:
	Node* copyRandomList(Node *head) {
		if (head == NULL) return NULL;
		Node* t = head;

		// Interwave node
		while (t != NULL) {
		    Node* newNode = new Node(t->val);
		    newNode->next = t->next;		
		    t->next = newNode;
		    t = newNode->next;
		}

		// Assign random node
		t = head;
		while (t != NULL) {
			Node* newNode = t->next;
			newNode->random = t->random == NULL ? NULL : t->random->next;
			t = newNode->next;
		}

		// Separate node
		t = head;
		Node* newList = t->next;
		Node* k = newList;
		while (t != NULL) {
			t->next = k->next;
			k->next = t->next == NULL ? NULL : t->next->next;
			t = t->next;
			k = k->next;
		}
		return k;
		
	}
};

int main() {
	return 0;
}
