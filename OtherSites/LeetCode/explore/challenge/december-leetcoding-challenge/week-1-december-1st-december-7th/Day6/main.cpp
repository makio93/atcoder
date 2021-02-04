#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(-1e9), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next) : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;
        queue<pair<Node*, int>> que;
        que.emplace(root, 0);
        while (!que.empty()) {
            auto p = que.front(); que.pop();
            Node* vnode = p.first;
            int dep = p.second, ndep = dep + 1;
            if (!que.empty() && que.front().second==dep) vnode->next = que.front().first;
            if (vnode->left != NULL) que.emplace(vnode->left, ndep);
            if (vnode->right != NULL) que.emplace(vnode->right, ndep);
        }
        return root;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<Node> node(n);
    for (int i=0; i<n; ++i) {
        string nval;
        cin >> nval;
        if (nval != "null") {
            node[i].val = stoi(nval);
            if (i-1 >= 0) {
                if ((i-1)%2==0) node[(i-1)/2].left = &node[i];
                else node[(i-1)/2].right = &node[i];
            }
        }
    }
    Node* res = cl.connect(&(node.front()));
    for (int i=0; i<n; ++i) {
        if (node[i].val != (int)(-1e9)) {
            cout << (node[i].val) << ' ';
            if (node[i].next == NULL) printf("#%c", (i<n-1?' ':'\n'));
        }
    }
    return 0;
}
