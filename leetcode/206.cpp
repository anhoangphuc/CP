#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return head;
        auto next = head->next;
        head -> next = NULL;
        while (next != NULL) {
            auto afterNext = next->next;
            next->next = head;
            head = next;
            next = afterNext;
        }
        return head;
    }
};
