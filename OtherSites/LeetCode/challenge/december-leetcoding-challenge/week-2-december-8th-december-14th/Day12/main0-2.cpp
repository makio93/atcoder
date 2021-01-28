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
    vector<int> depths;
    TreeNode* dfs(TreeNode* vnode, int d) {
        depths[vnode->val] = d;
        if (vnode->left==nullptr && vnode->right==nullptr) return vnode;
        pair<TreeNode*, TreeNode*> res = { nullptr, nullptr };
        if (vnode->left != nullptr) {
            res.first = dfs(vnode->left, d+1);
            depths[vnode->val] = max(depths[vnode->val], depths[vnode->left->val]);
        }
        if (vnode->right != nullptr) {
            res.second = dfs(vnode->right, d+1);
            depths[vnode->val] = max(depths[vnode->val], depths[vnode->right->val]);
        }
        if (res.first==nullptr || (res.first!=nullptr&&res.second!=nullptr&&depths[vnode->left->val]<depths[vnode->right->val])) return res.second;
        else if (res.second==nullptr || (res.second!=nullptr&&res.first!=nullptr&&depths[vnode->left->val]>depths[vnode->right->val])) return res.first;
        else return vnode;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (root == nullptr) return root;
        depths = vector<int>(501, -1);
        return dfs(root, 0);
    }
};

void odfs(TreeNode* node, vector<string>& vals, int id, int mnodes) {
    if (id >= mnodes) return;
    if (node == nullptr) {
        vals[id] = "null";
        return;
    }
    odfs(node->left, vals, id*2+1, mnodes);
    odfs(node->right, vals, id*2+2, mnodes);
    vals[id] = to_string(node->val);
}

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
    TreeNode* res = cl.subtreeWithAllDeepest(root);
    vector<string> vals(n, "null");
    odfs(res, vals, 0, n);
    int n2 = 0;
    for (int i=0; i<n; ++i) if (vals[i] != "null") n2 = max(n2, i+1);
    for (int i=0; i<n2; ++i) printf("%s%c", vals[i].c_str(), (i<n2-1?' ':'\n'));
    return 0;
}
