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
    map<int, set<pair<int, int>>> ord;
    void dfs(TreeNode* vnode, int y, int x) {
        if (vnode == nullptr) return;
        ord[x].emplace(y, vnode->val);
        dfs(vnode->left, y+1, x-1);
        dfs(vnode->right, y+1, x+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> ans;
        for (auto p : ord) {
            ans.push_back(vector<int>());
            for (auto itr=p.second.begin(); itr!=p.second.end(); ++itr) {
                ans.back().push_back(itr->second);
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}
