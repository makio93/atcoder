/*
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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

#define snuke(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define snuker(c, itr) for (__typeof((c).rbegin()) itr = (c).rbegin(); itr != (c).rend(); itr++)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v + n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }
*/

// 解説ページのC言語による解法　次の順列を作る関数を自作する

#include <stdio.h>

int p[7];

int nexp(int* a, int len) {
    int res = 0;
    int l = len-1, r = len-1;
    int tmp = 0;
    while (l>=0 && a[l]>=a[l+1]) --l;
    if (l >= 0) {
        res = 1;
        while (r>l && a[l]>=a[r]) --r;
        tmp = a[l]; a[l] = a[r]; a[r] = tmp;
        for (++l,r=len-1; l<r; ++l,--r) {
            tmp = a[l]; a[l] = a[r]; a[r] = tmp;
        }
    }
    return res;
}

int main(){
    int n, k;
    int t[8][8];
    int i, j;
    int ans = 0;
    int tot = 0;
    scanf("%d%d", &n, &k);
    for (i=0; i<n; ++i) for (j=0; j<n; ++j) {
        scanf("%d", &t[i][j]);
    }
    for (i=0; i<n-1; ++i) p[i] = i+1;
    do {
        tot = t[0][p[0]];
        for (i=0; i+1<n-1; ++i) tot += t[p[i]][p[i+1]];
        tot += t[p[n-2]][0];
        if (tot == k) ++ans;
    } while (nexp(p, n-1));
    printf("%d\n", ans);
    return 0;
}
