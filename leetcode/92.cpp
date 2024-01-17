#include <iostream>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(): val(0), next(nullptr) {}
	ListNode(int x): val(0), next(nullptr) {}
	ListNode(int x, ListNode* next): val(x), next(next){}
};

class Solution {
	public:
		ListNode* reverseBetween(ListNode* head, int left, int right) {
			ListNode* k = new ListNode(0, head);
			int cnt = 0;
			ListNode* leftPivot = k;
			ListNode* root = k;
			ListNode* rightPivot;
			while (k != NULL) {
				ListNode* nextNode = k->next;
				if (cnt == left - 1) {
					leftPivot = k;
				} else if (cnt == left) {
					rightPivot = k;	
				} else if (cnt > left && cnt <= right) {
					rightPivot->next = k->next;	
					k->next = leftPivot->next;
					leftPivot->next = k;
				} 
				cnt++;
				k = nextNode;
			}
			return root->next;
		}
};


int main() {
	return 0;
}

