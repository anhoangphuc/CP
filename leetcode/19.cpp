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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
                ListNode* p1 = head;
        ListNode* p2 = nullptr;
        int cnt{0};
        while (true) {
          
            if (cnt == n)
                p2 = head;
            if (p1 -> next == nullptr)
                break;
            cnt += 1;
            p1 = p1 -> next;
            if (p2 != nullptr)
                p2 = p2 -> next;
        }
        if (p2 != nullptr)
            p2 -> next = (p2 -> next) -> next;
        else
            head = head -> next;
        return head;
    }
};