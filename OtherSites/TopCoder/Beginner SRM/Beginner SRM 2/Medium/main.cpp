#include <bits/stdc++.h>
using namespace std;

class PairedMultiples {
public:
    int selectedTotal(vector<int> values, int multiple) {
        int n = values.size();
        vector<int> cnt(multiple);
        vector<long long> sum(multiple);
        for (int i=0; i<n; ++i) {
            cnt[values[i]%multiple]++;
            sum[values[i]%multiple] += values[i];
        }
        int m = cnt.size();
        long long ans = 0;
        for (int i=1; i<(m+1)/2; ++i) if (cnt[i]>0 && cnt[m-i]>0) ans += sum[i] + sum[m-i];
        if (cnt[0] > 1) ans += sum[0];
        if (m%2==0 && cnt[(m+1)/2]>1) ans += sum[(m+1)/2];
        return ans;
    }
};

int main(){
    return 0;
}
