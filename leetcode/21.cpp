#include <bits/stdc++.h>
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
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *r = nullptr;
        ListNode *head = nullptr;
        ListNode *nextNode;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 == nullptr) {
                nextNode = new ListNode(l2 -> val, nullptr);
                l2 = l2 -> next;
            } else if (l2 == nullptr) {
                nextNode = new ListNode(l1 -> val, nullptr);
                l1 = l1 -> next;
            } else if (l1 -> val <= l2 -> val) {
                nextNode = new ListNode(l1 -> val, nullptr);
                l1 = l1 -> next;
            } else {
                nextNode = new ListNode(l2 -> val, nullptr);
                l2 = l2 -> next;
            }
             if (head == nullptr) {
                head = nextNode;
                r = head;
            } else {
                r -> next = nextNode;
                r = r -> next;                 
             }
            
        }
        return head;
    }
};

int main() {
    Solution a = Solution();
    cout << "Hello world";
}