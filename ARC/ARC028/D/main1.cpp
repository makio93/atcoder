#include <bits/stdc++.h>
using namespace std;

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

const long long mod = 1000000007;

int main(){
    int n, m, q;
    cin >> n >> m >> q;
    vi a(n);
    rep(i, n) cin >> a[i];
    vector<vi> dp(n+1, vi(m+1, 0));
    dp[0][0] = 1;
    rep(i, n) {
        int sum = 0;
        rep(j, m+1) {
            (sum += dp[i][j])%=mod;
            if (j-a[i]-1>=0) ((sum-=dp[i][j-a[i]-1])+=mod)%=mod;
            dp[i+1][j] = sum;
        }
    }
    vector<vi> sdp(n, vi(m+1));
    rep(i, n-1) {
        int sum = 0;
        rep(j, m+1) {
            if (j>=1) (sum+=sdp[i][j-1])%=mod;
            if (j-a[i]-1>=0) ((sum-=sdp[i][j-a[i]-1])+=mod)%=mod;
            sdp[i][j] = ((dp[n][j]-sum)+mod)%mod;
        }
    }
    sdp[n-1] = dp[n-1];
    rep(i, q) {
        int k, x; 
        cin >> k >> x;
        --k;
        cout << sdp[k][m-x] << endl;
    }
    return 0;
}
