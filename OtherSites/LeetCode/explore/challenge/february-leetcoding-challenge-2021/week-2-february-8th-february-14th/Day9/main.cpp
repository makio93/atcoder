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
    int dfs(TreeNode* rnode, int sval) {
        if (rnode == nullptr) return sval;
        rnode->val += dfs(rnode->right, sval);
        return dfs(rnode->left, rnode->val);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        dfs(root, 0);
        return root;
    }
};

int main(){
    return 0;
}
