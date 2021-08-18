#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b, step) for (auto i = a; i < b; i += step)
#define repr(i, a, b, step) for (auto i = a; i > b; i -= step)

typedef pair<int, int> pii;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* res = new ListNode();
            ListNode* h = res;
            int carry(0);
            while (l1 != nullptr || l2 != nullptr) {
                int val1 = l1 == nullptr ? 0 : l1 -> val; 
                int val2 = l2 == nullptr ? 0 : l2 -> val;
                int temp = val1 + val2 + carry;
                carry = temp / 10;
                h -> val = temp % 10;
                h -> next = new ListNode();
                h = h -> next;
                if (l1 != nullptr) l1 = l1 -> next;
                if (l2 != nullptr) l2 = l2 -> next;
            }
            if (carry > 0)
                h -> val = carry;
            else
                h -> val = -1;

            h = res;
            while ((h -> next) -> val != -1) 
                h = h -> next;
            h -> next = nullptr;
            return res;
        }
};
int main() {
}
