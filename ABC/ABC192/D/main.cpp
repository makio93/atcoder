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

ll calc(string xi, ll mi) {
    if (mi <= 0) return 0;
    int len = sz(xi);
    if (len == 1) {
        if (stoll(xi) > mi) return 0;
        else return (ll)(LINF);
    }
    if ((xi.front()-'0') == 0) return calc(xi.substr(1), mi);
    ll sval = (ll)(pow((double)mi/((int)(xi.front()-'0')), (double)1.0/(len-1)))+10;
    while (sval > 0) {
        ll res = calc(xi.substr(1), mi-(ll)(pow(sval,len-1))*(xi.front()-'0'));
        if (sval <= res) return sval;
        --sval;
    }
    return 0;
}

int main(){
    string x;
    ll m;
    cin >> x >> m;
    if (sz(x) == 1) {
        if ((ll)(x.front()-'0') <= m) cout << 1 << endl;
        else cout << 0 << endl;
    }
    else {
        ll res = calc(x, m);
        int mval = 0;
        rep(i, sz(x)) mval = max(mval, (int)(x[i]-'0'));
        cout << max(0LL,res-mval) << endl;
    }
    return 0;
}
