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

struct SegmentTree {
    int n;
    vector<p(int)> dat;
    SegmentTree() { init(1); }
    SegmentTree(int n_) { init(n_); }
    void init(int n_) {
        n = 1;
        while (n < n_) n *= 2;
        dat = vector<p(int)>(2*n-1, p(int){0,-1});
    }
    void update(int k, int a) {
        int id = k;
        k += n-1;
        dat[k] = { a, id };
        while (k > 0) {
            k = (k-1) / 2;
            dat[k] = max(dat[k*2+1], dat[k*2+2]);
        }
    }
    p(int) query(int a, int b, int k=0, int l=0, int r=-1) {
        if (r == -1) { r = n; k = 0; l = 0; }
        if (r<=a || b<=l) return {0,-1};
        if (a<=l && r<=b) return dat[k];
        else {
            p(int) vl = query(a, b, k*2+1, l, (l+r)/2);
            p(int) vr = query(a, b, k*2+2, (l+r)/2, r);
            return max(vl, vr);
        }
    }
};

void dfs(int d, int l, int r, int n, SegmentTree& st, v(int)& dep) {
    if (r-l <= 0) return;
    if (r-l == 1) {
        dep[l] = d;
        return;
    }
    else {
        auto res = st.query(l, r);
        int id = res.second;
        dep[id] = d;
        dfs(d+1, l, id, n, st, dep);
        dfs(d+1, id+1, r, n, st, dep);
    }
}

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        int n;
        cin >> n;
        v(int) a(n);
        rep(i, n) cin >> a[i];
        SegmentTree st(n);
        rep(i, n) st.update(i, a[i]);
        v(int) dep(n, -1);
        dfs(0, 0, n, n, st, dep);
        rep(i, n) printf("%d%c", dep[i], (i<n-1?' ':'\n'));
    }
    return 0;
}