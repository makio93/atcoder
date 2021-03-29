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
    int dfs(vector<int>& vlst, vector<int>& voyage, TreeNode* pnode, int id=0) {
        if (pnode == nullptr) return id;
        if (voyage[id] != pnode->val) return -1;
        if (pnode->left!=nullptr && pnode->right!=nullptr) {
            if (voyage[id+1]==pnode->left->val || voyage[id+1]==pnode->right->val) {
                if (voyage[id+1] == pnode->right->val) {
                    vlst.push_back(pnode->val);
                    swap(pnode->left, pnode->right);
                }
                int lres = dfs(vlst, voyage, pnode->left, id+1);
                if (lres == -1) return -1;
                int rres = dfs(vlst, voyage, pnode->right, lres);
                if (rres == -1) return -1;
                return rres;
            }
            else return -1;
        }
        else if (pnode->left != nullptr) return dfs(vlst, voyage, pnode->left, id+1);
        else if (pnode->right != nullptr) return dfs(vlst, voyage, pnode->right, id+1);
        else return id+1;
    }
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> res;
        int result = dfs(res, voyage, root);
        if (result == -1) return vector<int>(1, -1);
        else return res;
    }
};

int main(){
    return 0;
}
