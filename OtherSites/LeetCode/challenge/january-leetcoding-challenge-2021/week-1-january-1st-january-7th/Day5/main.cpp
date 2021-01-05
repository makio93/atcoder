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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        while (head->next!=nullptr && head->val==head->next->val) {
            do head = head->next; while (head->next!=nullptr && head->val==head->next->val);
            if (head->next == nullptr) return head->next;
            head = head->next;
        }
        ListNode* p = head;
        while (p!=nullptr && p->next!=nullptr) {
            auto nextp = p->next;
            while (nextp->next!=nullptr && nextp->val==nextp->next->val) {
                do nextp = nextp->next; while (nextp->next!=nullptr && nextp->val==nextp->next->val);
                nextp = nextp->next;
                if (nextp == nullptr) break;
            }
            p->next = nextp;
            p = p->next;
        }
        return head;
    }
};

int main(){

    return 0;
}
