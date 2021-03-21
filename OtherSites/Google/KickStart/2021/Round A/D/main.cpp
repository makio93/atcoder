#include <bits/stdc++.h>
using namespace std;

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

int main(){
    int t;
    cin >> t;
    rep2(i1, 1, t) {
        int n;
        cin >> n;
        v(v(int)) a(n, v(int)(n)), b(n, v(int)(n));
        rep(i, n) rep(j, n) cin >> a[i][j];
        rep(i, n) rep(j, n) cin >> b[i][j];
        v(int) r(n), c(n);
        rep(i, n) cin >> r[i];
        rep(i, n) cin >> c[i];
        v(set<int>) rcnt(n), ccnt(n);
        map<int, set<p(int)>> blst;
        rep(i, n) rep(j, n) if (a[i][j] == -1) {
            blst[b[i][j]].emplace(i,j);
            rcnt[i].insert(j); ccnt[j].insert(i);
        }
        while (1) {
            bool operated = false;
            rep(i, n) if (sz(rcnt[i]) == 1) {
                operated = true;
                int ri = i, ci = *rcnt[i].begin();
                rcnt[i].clear();
                ccnt[ci].erase(ri);
                blst[b[ri][ci]].erase({ri,ci});
                if (blst[b[ri][ci]].empty()) blst.erase(b[ri][ci]);
            }
            rep(i, n) if (sz(ccnt[i]) == 1) {
                operated = true;
                int ci = i, ri = *ccnt[i].begin();
                ccnt[i].clear();
                rcnt[ri].erase(ci);
                blst[b[ri][ci]].erase({ri,ci});
                if (blst[b[ri][ci]].empty()) blst.erase(b[ri][ci]);
            }
            if (!operated) break;
        }
        ll ans = 0;
        while (!blst.empty()) {
            ans += blst.begin()->first;
            auto vrc = *blst.begin()->second.begin();
            blst.begin()->second.erase(blst.begin()->second.begin());
            if (blst.begin()->second.empty()) blst.erase(blst.begin());
            int ri = vrc.first, ci = vrc.second;
            rcnt[ri].erase(ci);
            ccnt[ci].erase(ri);
            if (sz(rcnt[ri])<=1 || sz(ccnt[ci])<=1) {
                while (1) {
                    bool operated = false;
                    rep(i, n) if (sz(rcnt[i]) == 1) {
                        operated = true;
                        int ri = i, ci = *rcnt[i].begin();
                        rcnt[i].clear();
                        ccnt[ci].erase(ri);
                        blst[b[ri][ci]].erase({ri,ci});
                        if (blst[b[ri][ci]].empty()) blst.erase(b[ri][ci]);
                    }
                    rep(i, n) if (sz(ccnt[i]) == 1) {
                        operated = true;
                        int ci = i, ri = *ccnt[i].begin();
                        ccnt[i].clear();
                        rcnt[ri].erase(ci);
                        blst[b[ri][ci]].erase({ri,ci});
                        if (blst[b[ri][ci]].empty()) blst.erase(b[ri][ci]);
                    }
                    if (!operated) break;
                }
            }
        }
        cout << "Case #" << i1 << ": " << ans << endl;
    }
    return 0;
}
