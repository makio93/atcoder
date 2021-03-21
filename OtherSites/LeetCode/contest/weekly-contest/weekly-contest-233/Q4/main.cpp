#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct Node {
        int num;
        Node *one = nullptr, *zero = nullptr;
        Node(int n=0) : num(n) {}
    };
public:
    int countPairs(vector<int>& nums, int low, int high) {
        int n = nums.size();
        Node* root = new Node(0);
        for (int i=0; i<n; ++i) {
            Node* vnode = root;
            vnode->num++;
            for (int j=15; j>=0; --j) {
                if (nums[i]&(1<<j)) {
                    if (vnode->one == nullptr) vnode->one = new Node(0);
                    vnode = vnode->one;
                    vnode->num++;
                }
                else {
                    if (vnode->zero == nullptr) vnode->zero = new Node(0);
                    vnode = vnode->zero;
                    vnode->num++;
                }
            }
        }
        int res = 0;
        for (int i=0; i<n; ++i) {
            int tar = high, sum = 0;
            Node* vnode = root;
            for (int j=15; j>=0; --j) {
                int b1 = (tar>>j)&1;
                if (b1) {
                    if ((nums[i]>>j)&1)
                }
            }
        }
    }
};

int main(){
    return 0;
}
