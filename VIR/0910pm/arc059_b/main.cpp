#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

using ll = long long;
using pii  = pair<int, int>;
using pll = pair<ll, ll>;
#define ull unsigned long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vc vector<char>
#define vs vector<string>
#define vpii vector<pii>
#define vpll vector<pll>

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; i++)
#define rep1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; i++)
#define repr(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rep1r(i, n) for (int i = ((int)(n)); i >= 1; i--)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define mp make_pair

#define INF (1e9)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    string s;
    cin >> s;
    int n = sz(s);
    vector<vi> sum0(26, vi(n+1)), sum1(26, vi(n));
    rep(i, 26) {
        char t = 'a' + i;
        for (int j=0; j<n; ++j) {
            if (s[j] == t) {
                sum0[i][j+1] = sum0[i][j] + 1;
                if (j>0) sum1[i][j] = sum1[i][j-1] + 1;
            }
            else {
                sum0[i][j+1] = sum0[i][j];
                if (j>0) sum1[i][j] = sum1[i][j-1];
            }
            if (j%2==1) sum0[i][j+1]--;
            else if (j>0) sum1[i][j]--;
        }
        if (sz(sum0[i])%2==0) sum0[i].back()--;
        if (sz(sum1[i])%2==0) sum1[i].back()--;
    }
    vector<vi> bsum0(26, vi(n)), bsum1(26, vi(n-1));
    rep(i, 26) rep(j, n) {
        bsum0[i][j] = sum0[i][j+1]-sum0[i][j];
    }
    rep(i, 26) rep(j, n-1) {
        bsum1[i][j] = sum1[i][j+1]-sum1[i][j];
    }
    rep(i, 26) {
        int l = 0, r = 0, val = 0;
        rep(j, n) {
            if (j%2==1 && r-l>0 && val>0) {
                printf("%d %d\n", l+2, r+2);
                return 0;
            }
            if (bsum0[i][j] < 0) {
                    val = 0;
                    l = r = j;
            }
            else {
                val += bsum0[i][j];
                ++r;
            }
        }
        l = 1; r = 1; val = 0;
        rep(j, n-1) {
            if (j%2==1 && r-l>0 && val>0) {
                printf("%d %d\n", l+2, r+2);
                return 0;
            }
            if (bsum1[i][j] < 0) {
                    val = 0;
                    l = r = j + 1;
            }
            else {
                val += bsum1[i][j];
                ++r;
            }
        }
    }
    printf("%d %d\n", -1, -1);
    return 0;
}
