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
        int n, m;
        cin >> n >> m;
        string p;
        cin >> p;
        v(p2(p(int),int)) llst(n+1), rlst(n+1);
        int nval = 0, uval = 0, dval = 0;
        rep(i, n) {
            int dv = (p[i]=='+'?1:-1);
            nval += dv;
            uval = max(uval, nval);
            dval = min(dval, nval);
            llst[i+1].first = { uval, dval };
            llst[i+1].second = nval;
        }
        nval = 0, uval = 0, dval = 0;
        repr(i, n) {
            int dv = (p[i]=='+'?-1:1);
            nval += dv;
            uval = max(uval, nval);
            dval = min(dval, nval);
            rlst[i].first = { uval, dval };
            rlst[i].second = nval;
        }
        rep(i, m) {
            int l, r;
            cin >> l >> r;
            --l;
            int d = rlst[r].second - llst[l].second;
            int nuval = max(llst[l].first.first, rlst[r].first.first-d);
            int ndval = min(llst[l].first.second, rlst[r].first.second-d);
            cout << (nuval-ndval+1) << endl;
        }
    }
    return 0;
}
