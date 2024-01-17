#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

class Solution {
    public:
        ListNode* removeNthFromEnd(ListNode* head, int n){
			int cnt = 0;
			ListNode* p1 = head;
			ListNode* p2 = NULL;
			ListNode* preP2 = NULL;
			while (p1 != NULL) {
					cnt += 1;
					if (cnt == n) {
				p2 = head;
					}
					p1 = p1->next;
					if (p1 == NULL) {
				if (preP2 == NULL) {
						head = head->next;
				} else {
						preP2->next = p2->next;
				}
				break;
					}
					preP2 = p2;
					if (p2 != NULL) {
				p2 = p2->next;
					}
			}
			return head;
	}		

};
