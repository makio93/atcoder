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
    vector<pair<long long, int>> sum;
    void dfs(vector<pair<long long, int>>& sum, TreeNode* pnode, int d=0) {
        if (pnode == nullptr) return;
        if (int(sum.size()) < d+1) sum.emplace_back(0LL, 0);
        sum[d].first += pnode->val;
        sum[d].second++;
        dfs(sum, pnode->left, d+1);
        dfs(sum, pnode->right, d+1);
    }
public:
    vector<double> averageOfLevels(TreeNode* root) {
        dfs(sum, root);
        int d = sum.size();
        vector<double> res(d);
        for (int i=0; i<d; ++i) res[i] = sum[i].first / (double)sum[i].second;
        return res;
    }
};

int main(){
    return 0;
}
