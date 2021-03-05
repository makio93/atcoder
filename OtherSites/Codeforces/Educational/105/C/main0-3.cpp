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

// 本番終了後、改めて自力考察、自力AC

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        int n, m;
        cin >> n >> m;
        v(int) a(n), b(m);
        rep(i, n) cin >> a[i];
        rep(i, m) cin >> b[i];
        v(vp(int)) apos(2), bpos(2);
        rep(i, n) {
            if (a[i] >= 0) apos[0].eb(a[i],-1);
            else apos[1].eb(abs(a[i]),-1);
        }
        rep(i, m) {
            if (b[i] >= 0) bpos[0].eb(b[i],-1);
            else bpos[1].eb(abs(b[i]),-1);
        }
        int ans = 0;
        rep(i, 2) {
            if (bpos[i].empty()) continue;
            VSORT(apos[i]); VSORT(bpos[i]);
            rep(j, sz(apos[i])) apos[i][j].second = j;
            rep(j, sz(bpos[i])) bpos[i][j].second = j;
            set<p(int)> alst, blst;
            rep(j, sz(apos[i])) alst.insert(apos[i][j]);
            rep(j, sz(bpos[i])) blst.insert(bpos[i][j]);
            v(int) lsum(sz(bpos[i])+1), rsum(sz(bpos[i])+1);
            rep(j, sz(bpos[i])) {
                auto itr = alst.upper_bound((p(int)){bpos[i][j].first,-1});
                int cnt = sz(alst);
                if (itr != alst.end()) cnt = itr->second;
                lsum[j+1] = cnt;
            }
            int rnsum = 0;
            repr(j, sz(bpos[i])) {
                rsum[j] = rnsum;
                auto itr = alst.upper_bound((p(int)){bpos[i][j].first,-1});
                if (itr!=alst.end() && itr->first==bpos[i][j].first) ++rnsum;
            }
            int mval = rnsum;
            rep(j, sz(bpos[i])) {
                auto itr = blst.upper_bound((p(int)){bpos[i][j].first-lsum[j+1],(int)(INF)});
                int bsub = sz(bpos[i]);
                if (itr != blst.end()) bsub = itr->second;
                mval = max(mval, max(0,(j+1)-bsub)+rsum[j]);
            }
            ans += mval;
        }
        cout << ans << endl;
    }
    return 0;
}
