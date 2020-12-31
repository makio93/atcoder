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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return head;
        ListNode *p = head, *pp = nullptr;
        while (p!=nullptr && p->next!=nullptr) {
            auto tmp = p->next;
            p->next = tmp->next;
            tmp->next = p;
            if (pp != nullptr) pp->next = tmp;
            else head = tmp;
            pp = tmp;
            pp = pp->next;
            p = p->next;
        }
        return head;
    }
};

int main() {
    Solution cl;
    int n;
    cin >> n;
    vector<ListNode> slist(n);
    ListNode* head = &(slist[0]);
    for (int i=0; i<n; ++i) {
        int vali;
        cin >> vali;
        slist[i].val = vali;
        if (i < n-1) slist[i].next = &(slist[i+1]);
        else slist[i].next = nullptr;
    }
    auto res = cl.swapPairs(head);
    while (res != nullptr) {
        printf("%d%c", res->val, ((res->next!=nullptr)?' ':'\n'));
        res = res->next;
    }
    return 0;
}
