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

int n;
v(int) pi;
v(vp(int)) g;
int ddfs(int vi, int dep=0) {
    int res = dep;
    rep(i, sz(g[vi])) {
        g[vi][i].first = ddfs(g[vi][i].second, dep+1);
        res = max(res, g[vi][i].first);
    }
    VSORT(g[vi]);
    return res;
}

v(p2(bool,p(int))) cnt;
bool dfs(int vi, bool turn=true) {
    if (cnt[vi].second != p(int)(-1,-1)) return cnt[vi].first;
    cnt[vi].second = { 0, 0 };
    if (turn) cnt[vi].second.first++;
    else cnt[vi].second.second++;
    bool res = !turn;
    rep(i, sz(g[vi])) {
        bool tmp = dfs(g[vi][i].second);
        if (res) {
            cnt[vi].second.first += cnt[g[vi][i].second].second.first;
            cnt[vi].second.second += cnt[g[vi][i].second].second.second;
        }
        else {
            cnt[vi].second.first += cnt[g[vi][i].second].second.second;
            cnt[vi].second.second += cnt[g[vi][i].second].second.first;
        }
        if (!tmp) res = !res;
    }
    return (cnt[vi].first = !res);
}

int main(){
    cin >> n;
    pi = v(int)(n);
    g = v(vp(int))(n);
    pi[0] = -1;
    rep2(i, 1, n-1) {
        cin >> pi[i];
        pi[i]--;
        g[pi[i]].eb(-1,i);
    }
    ddfs(0);
    cnt = v(p2(bool,p(int)))(n, p2(bool,p(int)){false, p(int)(-1,-1)});
    rep(i, n) dfs(i);
    cout << cnt[0].second.first << endl;
    return 0;
}
