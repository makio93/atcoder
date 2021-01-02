#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* dfs(TreeNode* vnode, int tval) {
    if (vnode == NULL) return NULL;
    if (vnode->val == tval) return vnode;
    TreeNode *lres = dfs(vnode->left, tval), *rres = dfs(vnode->right, tval);
    if (lres==NULL && rres==NULL) return NULL;
    else if (lres != NULL) return lres;
    else return rres;
}

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        int tval = target->val;
        TreeNode* res = dfs(cloned, tval);
        return res;
    }
};

int main(){
    return 0;
}
