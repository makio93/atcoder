#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        int n = 0;
        Node* p = head;
        vector<Node*> nmemo;
        while (p != NULL) {
            nmemo.push_back(p);
            p = p->next;
            ++n;
        }
        vector<Node*> res(n, NULL);
        for (int i=0; i<n; ++i) res[i] = new Node(0);
        for (int i=0; i<n; ++i) {
            res[i]->val = nmemo[i]->val;
            if (i+1<n) res[i]->next = res[i+1];
            else res[i]->next = NULL;
            if (nmemo[i]->random == NULL) res[i]->random = NULL;
            else {
                for (int j=0; j<n; ++j) if (nmemo[i]->random == nmemo[j]) res[i]->random = res[j];
            }
        }
        return res.front();
    }
};

int main(){
    return 0;
}
