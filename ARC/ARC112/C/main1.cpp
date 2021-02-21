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

// 解説AC

v(v(int)) g;
v(int) vcnt;
int dfs(int vi, int pi=-1) {
    v(int) odd, even;
    vcnt[vi]++;
    rep(i, sz(g[vi])) {
        int nv = g[vi][i];
        if (nv == pi) continue;
        int resi = dfs(nv, vi);
        if (vcnt[nv]%2==1) odd.pb(resi);
        else even.pb(resi);
        vcnt[vi] += vcnt[nv];
    }
    int res = 1;
    if (odd.empty() && even.empty()) return res;
    else if (odd.empty()) {
        rep(i, sz(even)) res += even[i];
        return res;
    }
    else if (even.empty()) {
        VSORT(odd);
        rep(i, sz(odd)) {
            if (i%2==0) res += odd[i];
            else res += odd[i] * -1;
        }
        return res;
    }
    else {
        VSORT(odd);
        int eplus = 0, eminus = 0;
        rep(i, sz(even)) {
            if (even[i] >= 0) eplus += even[i];
            else eminus += abs(even[i]);
        }
        res += eminus * -1;
        rep(i, sz(odd)) {
            if (i%2==0) res += odd[i];
            else res += odd[i] * -1;
        }
        if (sz(odd)%2==0) res += eplus;
        else res -= eplus;
        return res;
    }
}

int main(){
    int n;
    cin >> n;
    g = v(v(int))(n);
    rep2(i, 1, n-1) {
        int pi;
        cin >> pi;
        --pi;
        g[pi].pb(i);
        g[i].pb(pi);
    }
    vcnt = v(int)(n);
    cout << ((dfs(0)+n)/2) << endl;
    return 0;
}
