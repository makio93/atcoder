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
    map<p(int),int> board;
    rep(i, k) {
        int hi, wi;
        char ci;
        cin >> hi >> wi >> ci;
        --hi; --wi;
        const string clst = "RDX";
        rep(i2, sz(clst)) if (ci == clst[i2]) board[{hi,wi}] = i2;
    }
    v(v(v(mint))) dp(h, v(v(mint))(w, v(mint)(3)));
    if (board.find({0,0}) != board.end()) dp[0][0][board[{0,0}]] = 1;
    else rep(i, 3) dp[0][0][i] = 1;
    rep(i, h) rep(j, w) {
        if (i==0 && j==0) continue;
        mint nval = 0, nval2 = 0;
        if (i-1 >= 0) rep(i1, 3) {
            //if (board.find({i-1,j})!=board.end() && board[{i-1,j}]!=i1) continue;
            if (i1 == 0) continue;
            nval2 += dp[i-1][j][i1];
        }
        if (j-1 >= 0) rep(i1, 3) {
            //if (board.find({i,j-1})!=board.end() && board[{i,j-1}]!=i1) continue;
            if (i1 == 1) continue;
            nval += dp[i][j-1][i1] + nval2;
        }
        rep(i1, 3) {
            if (board.find({i,j})!=board.end() && board[{i,j}]!=i1) continue;
            dp[i][j][i1] += nval;
        }
    }
    mint ans = 0;
    rep(i, 3) {
        //if (board.find({h-1,w-1})!=board.end() && board[{h-1,w-1}]!=i) continue;
        ans += dp[h-1][w-1][i];
    }
    cout << ans.val() << endl;
    return 0;
}
