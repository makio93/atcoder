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
    map<int, int> vals;
    void dfs(TreeNode* tnode, int d=0) {
        if (tnode == nullptr) return;
        vals[d] = tnode->val;
        dfs(tnode->left, d+1);
        dfs(tnode->right, d+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root);
        int n = vals.size();
        vector<int> ans(n);
        for (auto p : vals) ans[p.first] = p.second;
        return ans;
    }
};

int main(){
    return 0;
}
