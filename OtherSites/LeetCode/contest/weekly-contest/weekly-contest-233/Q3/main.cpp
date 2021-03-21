#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        long long l = 1, r = (long long)maxSum * 2 + 1;
        while (r-l > 1) {
            long long c = (l + r) / 2, sum = 0;
            int llim = (int)max(0LL, (index-1)-(c-2)), rlim = (int)min((long long)n-1, index+(c-1));
            if (llim == 0) sum += ((c-1)+((c-1)-(index-1))) * (long long)index / 2LL;
            else sum += ((c-1)+1) * (c-1) / 2LL + ((long long)index-1)-(c-1) + 1;
            if (rlim == n-1) sum += (c+(c-(long long)(n-index-1))) * (long long)(n-index) / 2LL;
            else sum += (c+1) * c / 2LL + ((long long)n)-(index+c);
            if (sum <= (long long)maxSum) l = c;
            else r = c;
            cout << llim << ' ' << rlim << endl;
        }
        return (int)l;
    }
};

int main(){
    Solution cl;
    int n, index, maxSum;
    cin >> n >> index >> maxSum;
    cout << cl.maxValue(n, index, maxSum) << endl;
    return 0;
}
