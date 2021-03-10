#include <bits/stdc++.h>
using namespace std;

// コンテスト後に自力研究、もう1つヒントを見て実装、AC、一部修正

class Solution {
    struct Tree {
        int val;
        Tree *left, *right;
        Tree(int val_=0) {
            val = val_;
            left = NULL; right = NULL;
        }
    };
    void add(int tval, int d, Tree* vnode) {
        if (d == 31) vnode->val = tval;
        else {
            if ((tval>>(30-d))&1) {
                if (vnode->right == NULL) vnode->right = new Tree(0);
                add(tval, d+1, vnode->right);
            }
            else {
                if (vnode->left == NULL) vnode->left = new Tree(0);
                add(tval, d+1, vnode->left);
            }
        }
    }
    int dfs(int tar, int d, Tree* vnode) {
        if (d == 31) return vnode->val;
        else {
            if (vnode->left==NULL && vnode->right==NULL) return -1;
            if ((tar>>(30-d))&1) {
                if (vnode->right != NULL) return dfs(tar, d+1, vnode->right);
                else return dfs(tar, d+1, vnode->left);
            }
            else {
                if (vnode->left != NULL) return dfs(tar, d+1, vnode->left);
                else return dfs(tar, d+1, vnode->right);
            }
        }
    }
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> queries2(m);
        for (int i=0; i<m; ++i) {
            queries2[i].first = queries[i][1];
            queries2[i].second = { queries[i][0], i };
        }
        sort(queries2.begin(), queries2.end());
        vector<int> ans(m);
        Tree* root = new Tree(0);
        int id = 0;
        for (int i=0; i<m; ++i) {
            while (id<n && nums[id]<=queries2[i].first) {
                add(nums[id], 0, root);
                ++id;
            }
            int res = dfs((~(1<<31))^(queries2[i].second.first), 0, root);
            ans[queries2[i].second.second] = (res==-1)?(res):(res^queries2[i].second.first);
        }
        return ans;
    }
};

int main(){
    Solution cl;
    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for (int i=0; i<n; ++i) cin >> nums[i];
    vector<vector<int>> queries(m, vector<int>(2));
    for (int i=0; i<m; ++i) cin >> queries[i][0] >> queries[i][1];
    vector<int> res = cl.maximizeXor(nums, queries);
    for (int i=0; i<m; ++i) printf("%d%c", res[i], (i<m-1?' ':'\n'));
    return 0;
}
