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
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return nullptr;
        if (root->val>=low && root->val<=high) {
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            return root;
        }
        else if (root->val < low) return trimBST(root->right, low, high);
        else return trimBST(root->left, low, high);
    }
};

int main(){
    Solution cl;
    int n, low, high;
    cin >> n;
    vector<TreeNode> tnode(n);
    for (int i=0; i<n; ++i) {
        string nval;
        cin >> nval;
        if (nval != "null") {
            tnode[i].val = stoi(nval);
            if (i-1>=0 && (i-1)/2>=0) {
                if ((i-1)%2==0) tnode[(i-1)/2].left = &tnode[i];
                else tnode[(i-1)/2].right = &tnode[i];
            }
        }
    }
    cin >> low >> high;
    TreeNode* res = cl.trimBST(&(tnode[0]), low, high);
    vector<TreeNode*> pnode(n, nullptr);
    pnode[0] = res;
    int dnum = 1, snum = 0;
    while (1) {
        bool exist = false;
        for (int i=0; i<dnum; ++i) {
            if (snum+i >= n) {
                exist = false;
                break;
            }
            if (pnode[snum+i] != nullptr) {
                exist = true;
                if ((snum+i)*2+1 < n) pnode[(snum+i)*2+1] = pnode[snum+i]->left;
                if ((snum+i)*2+2 < n) pnode[(snum+i)*2+2] = pnode[snum+i]->right;
            }
        }
        snum += dnum;
        dnum *= 2;
        if (!exist || snum>=n) break;
    }
    int mcnt = 0;
    for (int i=0; i<n; ++i) if (pnode[i] != nullptr) mcnt = max(mcnt, i+1);
    for (int i=0; i<mcnt; ++i) {
        if (pnode[i] != nullptr) printf("%d%c", pnode[i]->val, (i<mcnt-1?' ':'\n'));
        else printf("null%c", (i<mcnt-1?' ':'\n'));
    }
    return 0;
}
