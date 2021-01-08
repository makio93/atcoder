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
    int n;
    ll m, p;
    cin >> n >> m >> p;
    v(ll) a(n);
    rep(i, n) cin >> a[i];
    ll mval = 0;
    rep(i, n) mval = max(mval, a[i]);
    if (mval > m) {
        cout << 1 << endl;
        return 0;
    }
    map<int, v(ll)> b;
    rep(i, n) {
        int cnt = 0;
        while (a[i]%p == 0) {
            a[i] /= p;
            ++cnt;
        }
        b[cnt].pb(a[i]);
    }
    repi(itr, b) RSORT(itr->second);
    bool one = true;
    repi(itr, b) if (itr->second[0] > 1) one = false;
    if (one) {
        cout << -1 << endl;
        return 0;
    }
    priority_queue<p2(int,ll), v(p2(int,ll)), greater<p2(int,ll)>> que;
    repi(itr, b) {
        if (itr->second[0] <= 1) continue;
        que.emplace(1+itr->first, -(itr->second[0]));
    }
    while (!que.empty()) {
        auto tp = que.top(); que.pop();
        int cnt = tp.first;
        ll val = tp.second * -1;
        if (val*mval > m) {
            cout << (cnt+1) << endl;
            return 0;
        }
        repi(itr, b) {
            if (itr->second[0] <= 1) continue;
            que.emplace(1+cnt+(itr->first), val*(itr->second[0])*(-1));
        }
    }
    return 0;
}
