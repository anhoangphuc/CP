#include <iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode* next;
	ListNode(): val(0), next(nullptr) {};
	ListNode(int x): val(x), next(nullptr) {};
	ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
	public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		int cnt = 0;
		ListNode* cur = head;
		ListNode* startSub;
		ListNode* endPreviousSub = NULL;
		ListNode* nextNode;
		ListNode* res = NULL;
		while (cur != NULL) {
			nextNode = cur -> next;
			cnt += 1;
			if (cnt == 1) {
				startSub = cur;
			} else if (cnt == k) {
				cur -> next = NULL;
				ListNode* oldStart = startSub;
				ListNode* newStart = reverseList(startSub);		
				if (endPreviousSub != NULL) {
					endPreviousSub->next = newStart;
				} else {
					res = newStart;
				}
				endPreviousSub = oldStart;	
				endPreviousSub->next = nextNode;
				cnt = 0;
			}
			cur = nextNode;
		}
		return res;
	}
	
	ListNode* reverseList(ListNode* t) {
		ListNode* cur = t;
		while (cur != NULL) {
			ListNode* nextNode = cur->next;
			cur->next = t;
			if (cur == t) {
				cur->next = NULL;
			}
			t = cur;
			cur = nextNode;
		}
		return t;
	}
};

int main() {
	ListNode* n5 = new ListNode(5);
	ListNode* n4 = new ListNode(4, n5);
	ListNode* n3 = new ListNode(3, n4);
	ListNode* n2 = new ListNode(2, n3);
	ListNode* n1 = new ListNode(1, n2);

	Solution a = Solution();
	ListNode* res = a.reverseKGroup(n1, 1);
	while (res != NULL) {
		cout << res->val << endl;
		res = res->next;
	}
}


