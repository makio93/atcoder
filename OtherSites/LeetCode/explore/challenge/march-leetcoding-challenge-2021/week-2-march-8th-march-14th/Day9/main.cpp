#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode* dfs(int v, int d, bool right, TreeNode* vnode, TreeNode* pnode=nullptr, int dep=1) {
        if (dep == d) {
            if (!right) return (new TreeNode(v, vnode, nullptr));
            else return (new TreeNode(v, nullptr, vnode));
        }
        if (vnode == nullptr) return vnode;
        else {
            vnode->left = dfs(v, d, false, vnode->left, vnode, dep+1);
            vnode->right = dfs(v, d, true, vnode->right, vnode, dep+1);
            return vnode;
        }
    }
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        return dfs(v, d, false, root);
    }
};

int main(){
    return 0;
}
