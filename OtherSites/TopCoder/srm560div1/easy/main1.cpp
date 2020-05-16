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
    int sum = 0;
    for (int i : keySizes) sum += i;
    if (sum < sz(frequencies)) return -1;
    RSORT(frequencies); RSORT(keySizes);
    int roop = 1, ans = 0, p = 0;
    for (int i : frequencies) {
        if (p>=sz(keySizes) || roop>keySizes[p]) {
            p = 0; ++roop;
        }
        ans += roop * i; ++p;
    }
    return ans;
}
