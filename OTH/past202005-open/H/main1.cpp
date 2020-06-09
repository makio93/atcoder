#include <bits/stdc++.h>
using namespace std;

// 総数を1000000007（素数）で割った余り
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

#define INF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int n, l;
    cin >> n >> l;
    vector<bool> x(l+1);
    rep(i, n) {
        int xi;
        cin >> xi;
        x[xi] = true;
    }
    vi t(3);
    rep(i, 3) cin >> t[i];
    vll dp(l+1, INF);
    dp[0] = 0LL;
    rep(i, l) {
        if (dp[i] == INF) continue;
        int del = (x[i]?t[2]:0);
        dp[i+1] = min(dp[i+1], dp[i]+t[0]+del);
        if (l-i >= 2) dp[i+2] = min(dp[i+2], dp[i]+t[0]+t[1]+del);
        else dp[l] = min(dp[l], dp[i]+t[0]/2+t[1]/2+del);
        if (l-i >= 4) dp[i+4] = min(dp[i+4], dp[i]+t[0]+t[1]*3+del);
        else {
            int run2 = (l-i)*2-1;
            dp[l] = min(dp[l], dp[i]+t[0]/2+t[1]*run2/2+del);
        }
    }
    cout << dp[l] << endl;
    return 0;
}
