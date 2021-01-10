#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<int> bit;
    BIT(int n_) : n(n_), bit(n_+1) {}
    int sum(int i) {
        int s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    void add(int i, int x) {
        while (i <= n) {
            bit[i] += x;
            i += i & -i;
        }
    }
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int n = instructions.size();
        BIT cnts((int)(1e5));
        long long cost = 0;
        const long long mod = (long long)(1e9) + 7;
        for (int i=0; i<n; ++i) {
            cnts.add(instructions[i], 1);
            int len1 = cnts.sum(instructions[i]-1), len2 = (i+1) - (cnts.sum(instructions[i]));
            cost = (cost + min(len1, len2)) % mod;
        }
        return (int)(cost);
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> instructions(n);
    for (int i=0; i<n; ++i) cin >> instructions[i];
    cout << cl.createSortedArray(instructions) << endl;
    return 0;
}
