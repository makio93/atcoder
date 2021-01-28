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
    vector<pair<int, int>> dep;
    int dfs1(TreeNode* node, int d=0) {
        if (node == nullptr) return d-1;
        dep[node->val] = { dfs1(node->left, d+1), dfs1(node->right, d+1) };
        return max(dep[node->val].first, dep[node->val].second);
    }
    TreeNode* dfs2(TreeNode* node, int tdep, int mode) {
        if (node == nullptr) return nullptr;
        if (max(dep[node->val].first,dep[node->val].second) < tdep) return nullptr;
        pair<bool, bool> cld = { (node->left!=nullptr&&dep[node->val].first>=tdep), (node->right!=nullptr&&dep[node->val].second>=tdep) };
        if (mode == 1) {
            if (cld.first) dfs2(node->left, tdep, mode);
            if (cld.second) dfs2(node->right, tdep, mode);
            return node;
        }
        else {
            if (node->left==nullptr && node->right==nullptr) return node;
            if (cld.first && cld.second) return node;
            else if (cld.first) return dfs2(node->left, tdep, mode);
            else if (cld.second) return dfs2(node->right, tdep, mode);
            else return nullptr;
        }
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (root == nullptr) return root;
        dep = vector<pair<int, int>>(501, {-1,-1});
        int mdep = dfs1(root);
        if (dep[root->val] == pair<int,int>(mdep,mdep)) return dfs2(root, mdep, 1);
        else {
            if (dep[root->val].first == mdep) return dfs2(root->left, mdep, 0);
            else return dfs2(root->right, mdep, 0);
        }
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
