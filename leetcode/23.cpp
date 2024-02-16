#include <vector>
#include <iostream>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};


struct cmp {
    bool operator() (ListNode* a, ListNode* b) const {
        return a->val < b->val;
    }
};


class Solution {
    multiset<ListNode*, cmp> s;
    public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto list: lists) {
            if (list != NULL)
                s.insert(list);
        }

        ListNode* res = NULL;
        ListNode* cur = NULL;
        while (!s.empty()) {
            auto top = *s.begin();
            if (res == NULL) {
                res = top;
                cur = res;
            } else {
                cur->next = top;
                cur = cur->next;
            }
            s.erase(s.begin());
            if (top->next != NULL) {
                s.insert(top->next);
            }
        }

        return res;
    }
};

int main() {
    Solution a = Solution();
    cout << "Hello world";
}
