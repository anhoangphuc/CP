#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(): val(0), next(nullptr) {}
	ListNode(int x): val(x), next(nullptr) {}
	ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
	public:
	ListNode* partition(ListNode* head, int x) {
		if (head == NULL) return NULL;
		ListNode* leftList = NULL;
		ListNode* rightList = NULL;
		ListNode* curLeftList = NULL;
		ListNode* curRightList = NULL;
		ListNode* cur = head;
		while (cur != NULL) {
			if (cur->val < x) {
				if (curLeftList == NULL) {
					leftList = cur;
				} else {
					curLeftList->next = cur;
				}
				curLeftList = cur;
			} else {
				if (curRightList == NULL) {
					rightList = cur;
				} else {
					curRightList->next = cur;
				}
				curRightList = cur;
			}
			cur = cur->next;
		}
		if (rightList != NULL) curRightList->next = NULL;
		if (leftList != NULL) {
			curLeftList->next = rightList;
			return leftList;
		} else {
			return rightList;
		}
	}
};

int main() {
	ListNode* n5 = new ListNode(5, NULL);
	ListNode* n4 = new ListNode(2, n5);
	ListNode* n3 = new ListNode(4, n4);
	ListNode* n2 = new ListNode(3, n3);
	ListNode* n1 = new ListNode(1, NULL);
	Solution a = Solution();
	ListNode* res = a.partition(n1, 5);	
	while (res != NULL) {
		cout << res->val << endl;
		res = res->next;
	}
}
