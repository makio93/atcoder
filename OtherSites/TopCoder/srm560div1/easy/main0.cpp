#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)

#define sz(x) ((int)(x).size())
#define rall(x) (x).rbegin(), (x).rend()

#define RSORT(x) sort(rall(x));

class TomekPhone {
public:
    int minKeystrokes(vi, vi);
};

int TomekPhone::minKeystrokes(vi frequencies, vi keySizes) {
    RSORT(frequencies); RSORT(keySizes);
    int d = 1, ans = 0, j = 0;
    rep(i, sz(frequencies)) {
        if (j==sz(keySizes) || keySizes[j]==0) {
            j = 0; ++d;
        }
        if (keySizes[j]==0) return -1;
        ans += d * frequencies[i];
        keySizes[j]--; ++j;
    }
    return ans;
}
