#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        vector<int> tmod(60);
        for (int i=0; i<n; ++i) tmod[time[i]%60]++;
        long long cnt = 0;
        for (int i=1; i<60-i; ++i) cnt += (long long)tmod[i] * tmod[60-i];
        for (int i=0; i<60; i+=30) cnt += (long long)tmod[i]*(tmod[i]-1) / 2;
        return (int)(cnt);
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<int> time(n);
    for (int i=0; i<n; ++i) cin >> time[i];
    cout << cl.numPairsDivisibleBy60(time) << endl;
    return 0;
}
