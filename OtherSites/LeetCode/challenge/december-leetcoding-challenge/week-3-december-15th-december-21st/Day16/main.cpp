#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    bool dfs(TreeNode* vnode, long long mnval, long long mxval) {
        if (vnode == nullptr) return true;
        bool res = (vnode->val>=mnval && vnode->val<=mxval);
        res &= (vnode->left==nullptr || ((vnode->left->val>=mnval)&&((vnode->left->val)<(vnode->val))));
        res &= (vnode->right==nullptr || ((vnode->right->val<=mxval)&&((vnode->right->val)>(vnode->val)))); 
        return (res && dfs(vnode->left,mnval,(long long)(vnode->val)-1) && dfs(vnode->right,(long long)(vnode->val)+1,mxval));
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, (1LL<<31)*(-1), (1LL<<31)-1);
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<string> ri(n);
    for (int i=0; i<n; ++i) cin >> ri[i];
    vector<TreeNode> tnode(n);
    TreeNode *root = &(tnode.front()), *ptr = nullptr;
    for (int i=0; i<n; ++i) {
        ptr = &(tnode[i]);
        if (ri[i] != "null") {
            ptr->val = stoi(ri[i]);
            if (i*2+1<n && ri[i*2+1]!="null") ptr->left = &(tnode[i*2+1]);
            if (i*2+2<n && ri[i*2+2]!="null") ptr->right = &(tnode[i*2+2]);
        }
    }
    if (cl.isValidBST(root)) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}
