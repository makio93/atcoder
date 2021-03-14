#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *tmp1, *tmp2, *p = head;
        int cnt = 0;
        while (p!=nullptr) {
            ++cnt;
            if (cnt == k) tmp1 = p;
            p = p->next;
        }
        int rk = cnt - k + 1;
        cnt = 0; p = head;
        while (p!=nullptr) {
            ++cnt;
            if (cnt == rk) tmp2 = p;
            p = p->next;
        }
        swap(tmp1->val, tmp2->val);
        return head;
    }
};

int main(){
    return 0;
}
