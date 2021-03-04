#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int acnt = 0, bcnt = 0;
        auto pnode_a = headA, pnode_b = headB;
        while (pnode_a != NULL) {
            ++acnt;
            pnode_a = pnode_a->next;
        }
        while (pnode_b != NULL) {
            ++bcnt;
            pnode_b = pnode_b->next;
        }
        pnode_a = headA; pnode_b = headB;
        if (acnt > bcnt) for (int i=0; i<(acnt-bcnt); ++i) pnode_a = pnode_a->next;
        if (bcnt > acnt) for (int i=0; i<(bcnt-acnt); ++i) pnode_b = pnode_b->next;
        while (pnode_a != pnode_b) {
            pnode_a = pnode_a->next;
            pnode_b = pnode_b->next;
        }
        return pnode_a;
    }
};

int main(){
    return 0;
}
