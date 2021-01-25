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

// (0,0),(1,0),(0,1)の3点の動きを追いかける解答方針のヒントだけ得てAC

int main(){
    int n, m, q;
    cin >> n;
    v(int) x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    cin >> m;
    v(vp(ll)) dps(m+1, vp(ll)(3));
    dps[0] = { {0, 0}, {1, 0}, {0, 1} };
    rep(i, m) {
        int op, pi = 0;
        cin >> op;
        switch (op) {
        case 1:
            rep(i2, 3) dps[i+1][i2] = { dps[i][i2].second, dps[i][i2].first*-1 };
            break;
        case 2:
            rep(i2, 3) dps[i+1][i2] = { dps[i][i2].second*-1, dps[i][i2].first };
            break;
        case 3:
            cin >> pi;
            rep(i2, 3) dps[i+1][i2] = { dps[i][i2].first+(pi-dps[i][i2].first)*2, dps[i][i2].second };
            break;
        case 4:
            cin >> pi;
            rep(i2, 3) dps[i+1][i2] = { dps[i][i2].first, dps[i][i2].second+(pi-dps[i][i2].second)*2 };
            break;
        }
    }
    cin >> q;
    v(int) a(q), b(q);
    rep(i, q) {
        cin >> a[i] >> b[i];
        b[i]--;
    }
    rep(i, q) {
        p(ll) dx = { x[b[i]]*(dps[a[i]][1].first-dps[a[i]][0].first), x[b[i]]*(dps[a[i]][1].second-dps[a[i]][0].second) };
        p(ll) dy = { y[b[i]]*(dps[a[i]][2].first-dps[a[i]][0].first), y[b[i]]*(dps[a[i]][2].second-dps[a[i]][0].second) };
        cout << (dps[a[i]][0].first+dx.first+dy.first) << ' ' << (dps[a[i]][0].second+dx.second+dy.second) << endl;
    }
    return 0;
}
