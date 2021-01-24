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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) return nullptr;
        pair<int, int> tari = { (int)(1e9), n+1 };
        for (int i=0; i<n; ++i) if (lists[i] != nullptr) {
            tari = min(tari, { lists[i]->val, i });
        }
        if (tari.second == n+1) return lists.front();
        ListNode* target = lists[tari.second];
        for (int i=0; i<n; ++i) {
            if (i == tari.second) continue;
            ListNode *ttar = target, *ptr = lists[i];
            while (ptr != nullptr) {
                if ((ttar->val)<=(ptr->val) && ((ttar->next==nullptr)||(ttar->next->val)>=(ptr->val))) {
                    auto ptr2 = ptr;
                    ptr = ptr->next;
                    ptr2->next = ttar->next;
                    ttar->next = ptr2;
                    ttar = ptr2;
                }
                else ttar = ttar->next;
            }
        }
        return target;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<ListNode*> lists(n, nullptr);
    vector<vector<ListNode>> lnodes(n);
    vector<int> m(n);
    for (int i=0; i<n; ++i) {
        cin >> m[i];
        lnodes[i] = vector<ListNode>(m[i]);
    }
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m[i]; ++j) {
            int vali;
            cin >> vali;
            lnodes[i][j].val = vali;
            if (j-1>=0) lnodes[i][j-1].next = &(lnodes[i][j]);
        }
        if (!lnodes[i].empty()) lists[i] = &(lnodes[i].front());
    }
    auto res = cl.mergeKLists(lists);
    while (res != nullptr) {
        if (res->next!=nullptr) cout << res->val << ' ';
        else cout << res->val << endl;
        res = res->next;
    }
    return 0;
}
