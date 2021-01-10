#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        int n = instructions.size();
        set<pair<int, int>> nums;
        map<int, int> cnts;
        long long cost = 0;
        const long long mod = (long long)(1e9) + 7;
        for (int i=0; i<n; ++i) {
            nums.emplace(instructions[i], i);
            cnts[instructions[i]]++;
            int len = distance(nums.begin(), nums.lower_bound({ instructions[i], -1 }));
            cost = (cost + min(len, ((i+1)-len-cnts[instructions[i]]))) % mod;
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
