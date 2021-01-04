#include <bits/stdc++.h>
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode *p2 = nullptr, *p = l1, *q = l2, *res = l1;
        while (q != nullptr) {
            if (p==nullptr || (p->val)>(q->val)) {
                if (p2 != nullptr) {
                    p2->next = q;
                    p2 = p2->next;
                }
                else {
                    p2 = q;
                    res = l2;
                }
                q = q->next;
                p2->next = p;

            }
            else {
                p2 = p;
                p = p->next;
            }
        }
        return res;
    }
};

int main(){
    return 0;
}
