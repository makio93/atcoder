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

// 本番中に作成、WA

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        int n, m;
        cin >> n >> m;
        v(int) a(n), b(m);
        rep(i, n) cin >> a[i];
        rep(i, m) cin >> b[i];
        set<int> alst;
        rep(i, n) alst.insert(a[i]);
        v(int) rok, lok;
        rep(i, m) {
            int tval = (alst.find(b[i])!=alst.end()?1:0);
            if (b[i] < 0) lok.pb(tval);
            else rok.pb(tval);
        }
        reverse(all(lok));
        v(int) rsum(sz(rok)+1), lsum(sz(lok)+1);
        repr(i, sz(rok)) rsum[i] = rsum[i+1] + rok[i];
        repr(i, sz(lok)) lsum[i] = lsum[i+1] + lok[i];
        int lzero = sz(lok);
        int rval = 0, lval = 0;
        rep(i, sz(rsum)-1) {
            int lcnt = upper_bound(all(a),b[lzero+i]) - upper_bound(all(a),-1);
            int l = max(0, b[lzero+i]-lcnt), r = b[lzero+i];
            int dcnt = distance(upper_bound(all(a),l), upper_bound(all(a),r));
            rval = max(rval, dcnt+rsum[i+1]);
        }
        rep(i, sz(lsum)-1) {
            int rcnt = distance(upper_bound(all(a),b[lzero-i-1]-1), upper_bound(all(a),0));
            int r = min(-1, b[lzero-i-1]+rcnt), l = b[lzero-i-1];
            int dcnt = distance(upper_bound(all(a),l), upper_bound(all(a),r));
            lval = max(lval, dcnt+lsum[i+1]);
        }
        cout << (rval+lval) << endl;
    }
    return 0;
}
