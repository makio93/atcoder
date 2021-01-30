#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int height = 0, mval = 0;
        for (int i=0; i<n; ++i) {
            height += gain[i];
            mval = max(mval, height);
        }
        return mval;
    }
};

int main(){
    return 0;
}
