#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        map<int, int> cnt;
        for (int i=0; i<n; ++i) cnt[candyType[i]]++;
        return min((int)(cnt.size()), n/2);
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> candyType(n);
    for (int i=0; i<n; ++i) cin >> candyType[i];
    cout << cl.distributeCandies(candyType) << endl;
    return 0;
}
