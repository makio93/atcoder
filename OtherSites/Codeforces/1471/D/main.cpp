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
    rep(i1, t) {
        int n;
        cin >> n;
        v(int) a(n);
        rep(i, n) cin >> a[i];
        v(vp(int)) ptest(n);
        rep(i, n) {
            int val = a[i];
            for (int j=2; j*j<=val; ++j) {
                if (val%j==0) {
                    ptest[i].eb(j, 0);
                    while (val%j == 0) {
                        ptest[i].back().second++;
                        val /= j;
                    }
                }
            }
            if (val > 1) ptest[i].eb(val, 1);
        }
        set<int> p;
        rep(i, n) rep(j, sz(ptest[i])) {
            p.insert(ptest[i][j].first);
        }
        map<int, int> ptype;
        int id = 0;
        repi(i, p) {
            ptype[*i] = id;
            ++id;
        }
        v(v(ll)) plist(n, v(ll)(sz(p)));
        int pnum = sz(p);
        rep(i, n) {
            rep(j, sz(ptest[i])) {
                int pid = ptype[ptest[i][j].first];
                plist[i][pid] += ptest[i][j].second;
            }
        }
        v(p2(v(ll),int)) lst;
        rep(i, n) lst.eb(plist[i],1);
        v(int) wlst;
        while (1) {
            map<v(int), v(p2(v(ll),int))> lcnt;
            rep(i, sz(lst)) {
                v(int) tmp(pnum);
                rep(j, pnum) tmp[j] = lst[i].first[j] % 2;
                lcnt[tmp].pb(lst[i]);
            }
            int mcnt = 0;
            for (auto p : lcnt) {
                int sum = 0;
                rep(i, sz(p.second)) sum += p.second[i].second;
                mcnt = max(mcnt, sum);
            }
            if (!wlst.empty() && mcnt==wlst.back()) break;
            wlst.pb(mcnt);
            v(p2(v(ll),int)) nlst;
            for (auto p : lcnt) {
                v(ll) lsum(pnum);
                int val = 0;
                rep(i, sz(p.second)) {
                    auto tmp = p.second[i];
                    rep(j, pnum) lsum[j] += tmp.first[j];
                    val += tmp.second;
                }
                nlst.eb(lsum, val);
            }
            lst = nlst;
        }
        int q;
        cin >> q;
        rep(i, q) {
            ll w;
            cin >> w;
            if (w > sz(wlst)-1) cout << wlst.back() << endl;
            else cout << wlst[(int)(w)] << endl;
        }
    }
    return 0;
}
