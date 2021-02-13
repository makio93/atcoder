#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;
using ull = unsigned long long;
#define v(t) vector<t>
#define p(t) pair<t, t>
#define p2(t, s) pair<t, s>
#define vp(t) v(p(t))

#define rep(i, n) for (int i=0,i##_len=((int)(n)); i<i##_len; ++i)
#define rep2(i, a, n) for (int i=((int)(a)),i##_len=((int)(n)); i<=i##_len; ++i)
#define repr(i, n) for (int i=((int)(n)-1); i>=0; --i)
#define rep2r(i, a, n) for (int i=((int)(n)),i##_len=((int)(a)); i>=i##_len; --i)

#define repi(itr, c) for (__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); ++itr)
#define repir(itr, c) for (__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); ++itr)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define eb emplace_back

#define INF (1e9)
#define LINF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)
#define DEPS (1e-10)

using mint = modint998244353;

int main(){
    int h, w, k;
    cin >> h >> w >> k;
    v(v(int)) board(h, v(int)(w, -1));
    rep(i, k) {
        const string ctar = "RDX";
        int hi, wi, ci = -1;
        char tci;
        cin >> hi >> wi >> tci;
        hi--; wi--;
        rep(j, sz(ctar)) if (tci == ctar[j]) ci = j;
        board[hi][wi] = ci;
    }
    v(v(mint)) dp(2, v(mint)(w));
    dp[0][0] = 1;
    rep(i, h) {
        dp[(i+1)%2] = v(mint)(w);
        rep(j, w) {
            if (i==h-1 && j==w-1) continue;
            if (board[i][j] == -1) dp[i%2][j] = dp[i%2][j] * 2 / 3;
            if (i+1<h) {
                if (board[i][j] != 0) dp[(i+1)%2][j] += dp[i%2][j];
            }
            if (j+1<w) {
                if (board[i][j] != 1) dp[i%2][j+1] += dp[i%2][j];
            }
        }
    }
    mint ans = dp[(h-1)%2][w-1] * mint(3).pow(h*w-k);
    cout << ans.val() << endl;
    return 0;
}
