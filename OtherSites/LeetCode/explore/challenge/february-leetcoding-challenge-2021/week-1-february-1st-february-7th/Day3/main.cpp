#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    set<ListNode*> visited;
public:
    bool hasCycle(ListNode *head) {
        if (visited.find(head) != visited.end()) return true;
        if (head == NULL) return false;
        visited.insert(head);
        return hasCycle(head->next);
    }
};

int main(){
    return 0;
}
