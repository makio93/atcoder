#include <bits/stdc++.h>
using namespace std;

class Solution {
    long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
    long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
public:
    int reinitializePermutation(int n) {
        vector<int> arr2(n);
        for (int i=0; i<n; ++i) {
            if (i%2==0) arr2[i/2] = i;
            else arr2[n/2+(i-1)/2] = i;
        }
        set<int> r;
        for (int i=0; i<n; ++i) {
            int ri = 1, aval = arr2[i];
            if (aval != i) {
                while (aval != i) {
                    aval = arr2[aval];
                    ++ri;
                }
            }
            r.insert(ri);
        }
        if ((int)(r.size()) == 1) return (*r.begin());
        else if (r.size()==2 && *(r.begin())==1) return (*r.rbegin());
        else {
            auto itr = r.begin();
            long long res = *itr;
            ++itr;
            while (itr != r.end()) {
                res = lcm(res, (long long)(*itr));
                ++itr;
            }
            return (int)(res);
        }
    }
};

int main(){
    return 0;
}
