#include <bits/stdc++.h>
using namespace std;

// 自力AC

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
    stack<TreeNode*> bst;
public:
    BSTIterator(TreeNode* root) { bst.push(root); }
    int next() {
        while (!bst.empty()) {
            auto p = bst.top(); bst.pop();
            if (p->left==nullptr&&p->right==nullptr) {
                return p->val;
            }
            auto lnode = p->left, rnode = p->right;
            p->left = nullptr; p->right = nullptr;
            if (rnode != nullptr) bst.push(rnode);
            bst.push(p);
            if (lnode != nullptr) bst.push(lnode);
        }
        return (int)(-1e9);
    }
    bool hasNext() { return (!bst.empty()); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main(){

    return 0;
}
