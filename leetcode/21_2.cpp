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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;
        ListNode* preList = NULL;
        ListNode* res = NULL;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                if (preList == NULL) {
                    preList = list1;
                    res = preList;
                } else {
                    preList->next = list1;
                    preList = preList->next;
                }
                list1 = list1->next;
            } else {
                if (preList == NULL) {
                    preList = list2;
                    res = preList;
                } else {
                    preList->next = list2;
                    preList = preList->next;
                }
                list2 = list2->next;
            }
        }
        while (list1 != NULL) {
            preList->next = list1;
            list1 = list1->next;
            preList = preList->next;
        }
        while (list2 != NULL) {
            preList->next = list2;
            list2 = list2->next;
            preList = preList->next;
        }
        preList->next = NULL;
        return res;
    }
};
