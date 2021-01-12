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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0), *now = res;
        while (l1!=nullptr || l2!=nullptr) {
            int nval = (l1!=nullptr?l1->val:0) + (l2!=nullptr?l2->val:0) + now->val;
            now->val = nval%10;
            if (l1!=nullptr) l1 = l1->next;
            if (l2!=nullptr) l2 = l2->next;
            if (!(l1==nullptr && l2==nullptr && nval/10==0)) {
                now->next = new ListNode(nval/10);
                now = now->next;
            }
        }
        return res;
    }
};

int main(){
    
    return 0;
}
