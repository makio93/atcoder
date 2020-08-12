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
    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;
        vi w(n);
        rep(i, n) cin >> w[i];
        vector<vi> dp(n+1, vi(n+1, 0));
        for (int wi=2; wi<=n; ++wi) rep(l, n) {
            int r = l + wi;
            if (r > n) continue;
            if (abs(w[l]-w[r-1])<=1&&dp[l+1][r-1]==wi-2) dp[l][r] = wi;
            else {
                for (int k=l+1; k<r; ++k) {
                    dp[l][r] = max(dp[l][r], dp[l][k]+dp[k][r]);
                }
            }
        }
        cout << dp[0][n] << endl;
    }
    return 0;
}
