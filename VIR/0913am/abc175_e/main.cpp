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
    int r, c, k;
    cin >> r >> c >> k;
    vector<vi> rc(r, vi(c, -1));
    rep(i, k) {
        int ri, ci, v;
        cin >> ri >> ci >> v;
        --ri; --ci;
        rc[ri][ci] = v;
    }
    vector<vll> dp(4, vll(c+1, 0));
    rep(i, r) rep1(j, c) {
        ll up = 0;
        rep(i2, 4) up = max(up, dp[i2][j]);
        rep(t, 4) {
            if (rc[i][j-1] == -1) {
                dp[t][j] = max({dp[t][j], up, dp[t][j-1]});
            }
            else {
                if (t+1 <= 3) dp[t+1][j] = max({dp[t+1][j], up+rc[i][j-1], dp[t][j-1]+rc[i][j-1]});
                dp[t][j] = max({dp[t][j], up, dp[t][j-1]});
            }
        }
    }
    cout << dp[3][c] << endl;
    return 0;
}
