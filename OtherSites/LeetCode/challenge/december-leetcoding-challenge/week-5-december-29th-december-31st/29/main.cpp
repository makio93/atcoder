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

int dfs(TreeNode* node, vector<int>& cnts) {
    cnts[node->val]++;
    int res = 0;
    if (node->left==nullptr && node->right==nullptr) {
        int odds = 0, sum = 0;
        for (int i=1; i<=9; ++i) {
            if (cnts[i]%2==1) ++odds;
            sum += cnts[i];
        }
        if (sum%2==1) {
            if (odds == 1) ++res;
        }
        else {
            if (odds == 0) ++res;
        }
    }
    else {
        if (node->left != nullptr) res += dfs(node->left, cnts);
        if (node->right != nullptr) res += dfs(node->right, cnts);
    }
    cnts[node->val]--;
    return res;
}

class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        vector<int> cnts(10);
        int res = dfs(root, cnts);
        return res;
    }
};

int main() {
    Solution cl;
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i=0; i<n; ++i) {
        string value;
        cin >> value;
        if (value != "null") values[i] = stoi(value);
    }
    vector<TreeNode> tree(n);
    for (int i=0; i<n; ++i) {
        if (values[i] == 0) continue;
        tree[i].val = values[i];
        if (i > 0) {
            int p = (i-1) / 2;
            if ((i-1)%2==0) tree[p].left = &tree[i];
            else tree[p].right = &tree[i];
        }
    }
    int res = cl.pseudoPalindromicPaths(&tree[0]);
    cout << res << endl;
    return 0;
}
