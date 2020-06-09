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

#define INF (1e9)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int w;
    cin >> w;
    int n, k;
    cin >> n >> k;
    vi a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    vector<vector<vi>> dp(w+1, vector<vi>(k+1, vi(n+1)));
    rep(h, n) repr(i, w+1) rep(j, k+1) {
        if (i<a[h] || j==0) {
            dp[i][j][h+1] = dp[i][j][h];
        }
        else {
            dp[i][j][h+1] = max(dp[i][j][h], dp[i-a[h]][j-1][h]+b[h]);
        }
    }
    cout << dp[w][k][n] << endl;
    return 0;
}
