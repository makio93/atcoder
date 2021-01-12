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

// きまぐれ精進、自力で提出分、WA+TLEに

int n;
v(ll) val;
v(v(p2(ll,int))) mval(2);
void dfs(int mode, int v, int h, ll nval) {
    int id = (mode==1?0:1), mul = (id==0?-1:1);
    mval[id][h] = max(mval[id][h], {nval,v*mul});
    if (h==0 || v+mode<0 || v+mode>=n) return;
    dfs(mode, v+mode, h-1, nval+val[v]);
    if (h-1>0 && val[v]<0) dfs(mode, v+mode, h-2, nval);
}

int main(){
    int k;
    cin >> n >> k;
    val = v(ll)(n);
    rep(i, n) cin >> val[i];
    rep(i, 2) mval[i] = v(p2(ll,int))(k+1, {-LINF,INF});
    mval[0][0] = { 0, 0 };
    mval[1][0] = { 0, n-1 };
    dfs(1, 0, k, 0);
    dfs(-1, n-1, k, 0);
    rep(i, k+1) mval[0][i].second *= -1;
    ll ans = 0;
    rep(i, k+1) for (int j=k-i; j<=k; ++j) {
        if (mval[0][i].second+mval[1][j].second <= n+2) ans = max(ans, mval[0][i].first+mval[1][j].first);
    }
    cout << ans << endl;
    return 0;
}
