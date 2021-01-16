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

int h, w, k;
map<p(int),int> board;
v(v(bool)) visited;
v(v(mint)) dp;
mint dfs(int i1, int j1) {
    if (visited[i1][j1]) return dp[i1][j1];
    visited[i1][j1] = true;
    if (i1==h-1 && j1==w-1) {
        if (board.find({i1,j1}) != board.end()) return (dp[i1][j1] = 1);
        else return (dp[i1][j1] = 3);
    }
    mint res = 0;
    int c = -1;
    if (board.find({i1,j1}) != board.end()) {
        c = board[{i1,j1}];
    }
    if (c==-1 || c==0) {
        if (j1+1 < w) res += dfs(i1, j1+1);
    }
    if (c==-1 || c==1) {
        if (i1+1 < h) res += dfs(i1+1, j1);
    }
    if (c==-1 || c==2) {
        if (j1+1 < w) res += dfs(i1, j1+1);
        if (i1+1 < h) res += dfs(i1+1, j1);
    }
    return (dp[i1][j1] = res);
}

int main(){
    cin >> h >> w >> k;
    rep(i, k) {
        int hi, wi;
        char ci;
        cin >> hi >> wi >> ci;
        --hi; --wi;
        const string clst = "RDX";
        rep(i2, sz(clst)) if (ci == clst[i2]) board[{hi,wi}] = i2;
    }
    visited = v(v(bool))(h, v(bool)(w));
    dp = v(v(mint))(h, v(mint)(w, -1));
    mint ans = dfs(0, 0);
    cout << ans.val() << endl;
    return 0;
}
