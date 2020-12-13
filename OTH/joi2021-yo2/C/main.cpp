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
//#define mp make_pair

#define INF (1e9)
#define INF2 (1e18)
#define PI (acos(-1))
#define EPS (1e-7)

ull gcd(ull a, ull b) { return b ? gcd(b, a % b) : a; }
ull lcm(ull a, ull b) { return a / gcd(a, b) * b; }

int main(){
    int n;
    ll d, k;
    cin >> n >> d >> k;
    vector<pair<ll, int>> sp(n);
    rep(i, n) {
        cin >> sp[i].second >> sp[i].first;
        sp[i].second--;
    }
    VSORT(sp);
    vector<vector<pair<ll, int>>> sn(2);
    rep(i, n) {
        sn[sp[i].second].emplace_back(sp[i].first, i);
    }
    vector<vi> dp(n+1, vi(2));
    rep(i, n) {
        ll now = 0;
        if (i > 0) now = sp[i-1].first + 1;
        rep(j, 2) {
            if (sp[i].second == j) dp[i+1][j] = max(dp[i+1][j], dp[i][j]+1);
            else dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            ll next = now + (d + dp[i][j] * k);
            int np = distance(sn[1-j].begin(), lower_bound(all(sn[1-j]), pair<ll, int>(next, 0)));
            if (np < sz(sn[1-j])) {
                dp[sn[1-j][np].second+1][1-j] = max(dp[sn[1-j][np].second+1][1-j], dp[i][j]+1);
            }
        }
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
    return 0;
}
