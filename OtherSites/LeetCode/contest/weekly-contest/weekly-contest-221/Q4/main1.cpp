#include <bits/stdc++.h>
using namespace std;

// 解説を見てAC

class Solution {
    struct Node { Node *zero_node=nullptr, *one_node=nullptr; };
    Node* root = new Node();
    void insert(int num) {
        auto ptr = root;
        for (int i=31; i>=0; --i) {
            if ((num>>i)&1) {
                if (ptr->one_node == nullptr) ptr->one_node = new Node();
                ptr = ptr->one_node;
            }
            else {
                if (ptr->zero_node == nullptr) ptr->zero_node = new Node();
                ptr = ptr->zero_node;
            }
        }
    }
    int searchXor(int num) {
        if (root->zero_node==nullptr && root->one_node==nullptr) return -1;
        auto ptr = root;
        int res = 0;
        for (int i=31; i>=0; --i) {
            if ((num>>i)&1) {
                if (ptr->zero_node != nullptr) {
                    res += 1<<i;
                    ptr = ptr->zero_node;
                }
                else ptr = ptr->one_node;
            }
            else {
                if (ptr->one_node != nullptr) {
                    res += 1<<i;
                    ptr = ptr->one_node;
                }
                else ptr = ptr->zero_node;
            }
        }
        return res;
    }
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size(), m = queries.size();
        vector<vector<int>> que2;
        for (int i=0; i<m; ++i) que2.push_back({queries[i][1], queries[i][0], i});
        sort(nums.begin(), nums.end());
        sort(que2.begin(), que2.end());
        int id = 0;
        vector<int> res(m);
        for (int i=0; i<m; ++i) {
            while (id<n && nums[id]<=que2[i][0]) {
                insert(nums[id]);
                ++id;
            }
            res[que2[i][2]] = searchXor(que2[i][1]);
        }
        return res;
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
