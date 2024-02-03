#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(): val(0), next(nullptr) {}
	ListNode(int x): val(x), next(nullptr) {}
	ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
	public:
		ListNode* sortList(ListNode* head) {
			if (head == NULL || head->next == NULL) return head;
			auto mid = findMid(head);
			auto second = mid->next;
			mid->next = NULL;
			auto part1 = sortList(head);
			auto part2 = sortList(second);

			return merge(part1, part2);
		}

		ListNode* findMid(ListNode* head) {
			auto slow = head;
			auto fast = head->next;
			while (fast != NULL && fast->next != NULL) {
				fast = fast->next->next;
				slow = slow->next;
			}
			return slow;

		}

		ListNode* merge(ListNode* part1, ListNode* part2) {
			if (part1 == NULL) return part2;
			if (part2 == NULL) return part1;
			if (part1->val < part2->val) {
				auto next = part1->next;
				part1->next = merge(next, part2);
				return part1;
			} else {
				auto next = part2->next;
				part2->next = merge(part1, next);
				return part2;
			}
		}
};

int main() {
	ListNode* n1 = new ListNode(-3, NULL);
	ListNode* n2 = new ListNode(1, n1);
	ListNode* n3 = new ListNode(2, n2);
	ListNode* n4 = new ListNode(-4, n3);
	ListNode* n5 = new ListNode(-1, n4);
	Solution a = Solution();
	auto res = a.sortList(n5);
	while (res != NULL) {
		cout << res -> val << endl;
		res = res -> next;
	}
}


