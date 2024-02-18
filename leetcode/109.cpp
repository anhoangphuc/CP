#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(): val(0), next(nullptr) {}
	ListNode(int x): val(x), next(nullptr) {}
	ListNode(int x, ListNode* next): val(x), next(next) {}
};
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
	public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL)
            return NULL;
        auto med = findMed(head);
        TreeNode* res = new TreeNode(med->val);
        if (head != med)
            res->left = sortedListToBST(head);
        else
            res->left = NULL;
        res->right = sortedListToBST(med->next);
        return res;
    }

private:
    ListNode* findMed(ListNode* head) {
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;
        ListNode* prev = NULL;
        while (fastPtr != NULL && fastPtr->next != NULL) {
            prev = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        if (prev != NULL) {
            prev->next = NULL;
        }
        return slowPtr;
    }
};

int main() {
	return 0;
}
