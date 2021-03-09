#include <bits/stdc++.h>
using namespace std;

// コンテスト後に自力研究、ヒントだけ見て実装、WA

class Solution {
    struct Tree {
        long long val;
        Tree *left, *right;
        Tree(long long val_=0LL) {
            val = val_;
            left = NULL; right = NULL;
        }
    };
    void add(long long tval, int d, Tree* vnode) {
        if (d == 31) vnode->val = tval;
        else {
            if ((tval>>d)&1) {
                if (vnode->right == NULL) vnode->right = new Tree(0);
                add(tval, d+1, vnode->right);
            }
            else {
                if (vnode->left == NULL) vnode->left = new Tree(0);
                add(tval, d+1, vnode->left);
            }
        }
    }
    long long dfs(long long tar, int d, Tree* root) {
        if (d == 31) return root->val;
        else {
            if (root->left==NULL && root->right==NULL) return -1;
            if ((tar>>d)&1) {
                if (root->right != NULL) return dfs(tar, d+1, root->right);
                else return dfs(tar, d+1, root->left);
            }
            else {
                if (root->left != NULL) return dfs(tar, d+1, root->left);
                else return dfs(tar, d+1, root->right);
            }
        }
    }
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int,int>>> queries2(m);
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
                add((long long)nums[id], 0, root);
                ++id;
            }
            long long res = dfs(((1LL<<33)-1)^((long long)queries2[i].second.first), 0, root);
            ans[queries2[i].second.second] = (int)((res==-1LL)?(res):(res^(long long)queries2[i].second.first));
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
