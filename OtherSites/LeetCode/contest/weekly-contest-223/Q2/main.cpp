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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0, kval = -1, rkval = -1;
        auto p = head;
        while (p != nullptr) {
            ++n;
            if (n == k) kval = p->val;
            p = p->next;
        }
        p = head;
        for (int i=1; i<=n; ++i) {
            if (i == n-k+1) {
                rkval = p->val;
                p->val = kval;
                break;
            }
            p = p->next;
        }
        p = head;
        for (int i=1; i<=n; ++i) {
            if (i == k) {
                p->val = rkval;
                break;
            }
            p = p->next;
        }
        return head;
    }
};

int main(){
    
    return 0;
}
