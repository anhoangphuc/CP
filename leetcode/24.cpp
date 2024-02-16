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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head -> next) return head;

        ListNode *start = nullptr, *prev = nullptr, *first = nullptr, *second = nullptr;

        while (head) {
            if (head -> next) {
                first = head;
                second = head -> next;
                head = head -> next -> next;
                second -> next = first;
            } else {
                second = head;
                first = nullptr;
                head = head -> next;
            }

            if (prev)
                prev -> next = second;
            else
                start = second;
            prev = first;
        }
        if (first)
            first -> next = nullptr;
        else
            second -> next = nullptr;
        return start;
    }
};

int main() {
    Solution a = Solution();
    cout << "Hello world";
}