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
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL) return NULL;
		ListNode* cur = head;
		ListNode* last = NULL;
		int len = 0;
		while (cur != NULL) {
			len += 1;
			if (cur->next == NULL) last = cur;
			cur = cur->next;
		}

		cur = head;
		k = k % len;
		cout <<  "LEN " << len << " " << k << endl;
		if (k == 0) return head;
		int cnt = 0;
		while (cur != NULL) {
			cnt += 1;
			if (cnt == len - k) {
				break;
			}
			cur = cur->next;
		}
		cout << "Cur " << cur->val << " " << last->val << " " << head->val << endl;
		ListNode* res = cur->next;
		last->next = head;
		cur->next = NULL;
		return res;
	}
};

int main() {
	ListNode* n5 = new ListNode(5, NULL);
	ListNode* n4 = new ListNode(4, n5);
	ListNode* n3 = new ListNode(3, n4);
	ListNode* n2 = new ListNode(2, n3);
	ListNode* n1 = new ListNode(1, n2);
	Solution a = Solution();
	ListNode* res = a.rotateRight(n1, 5);	
	while (res != NULL) {
		cout << res->val << endl;
		res = res->next;
	}
}
