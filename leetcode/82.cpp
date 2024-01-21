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
	ListNode* deleteDuplicates(ListNode* head) {
		        if (head == NULL) return NULL;
        ListNode* cur = head;
        ListNode* leftPivot = NULL;
        int removeVal(0);
        int duplicateVal = -101;
        while (cur != NULL) {
            if (cur->val != duplicateVal) {
                if (cur->next == NULL) {
                    if (leftPivot == NULL) {
                        leftPivot = cur;
                        head = leftPivot;
                    } else {
                        leftPivot->next = cur;
                        leftPivot = cur;
                    }
                } else {
                    if (cur->next->val != cur->val) {
                        if (leftPivot == NULL) {
                            leftPivot = cur;
                            head = leftPivot;
                        } else {
                            leftPivot->next = cur;
                            leftPivot = cur;
                        }
                    } else {
                        duplicateVal = cur->val;
                    }
                }
            }
            cur = cur->next;
        }
        if (leftPivot == NULL) return NULL;
        leftPivot->next = NULL;
        return head;

	}
};

int main() {
	//ListNode* n5 = new ListNode(4, NULL);
	//ListNode* n4 = new ListNode(3, n5);
	//ListNode* n3 = new ListNode(2, n4);
	ListNode* n2 = new ListNode(1, NULL);
	ListNode* n1 = new ListNode(1, n2);
	Solution a = Solution();
	ListNode* res = a.deleteDuplicates(n1);	
	while (res != NULL) {
		cout << res->val << endl;
		res = res->next;
	}
}
