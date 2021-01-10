#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        sort(jobs.rbegin(), jobs.rend());
        vector<int> task(k);
        for (int i=0; i<min(n,k); ++i) task[i] += jobs[i];
        if (n<=k) return jobs[0];
        int mxval = 1, ans = (int)(1e9);
        for (int i=0; i<(n-k); ++i) mxval *= k;
        for (int i=0; i<mxval; ++i) {
            auto ntask = task;
            for (int j=0; j<(n-k); ++j) {
                int tmpi = i;
                for (int j2=0; j2<j; ++j2) tmpi /= k;
                ntask[tmpi%k] += jobs[k+j];
            }
            sort(ntask.rbegin(), ntask.rend());
            ans = min(ans, ntask[0]);
        }
        return ans;
    }
};

int main(){
    
    return 0;
}
