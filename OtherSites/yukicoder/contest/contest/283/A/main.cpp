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
    int w, h, x;
    cin >> w >> h >> x;
    int mcnt = max(1,w%3) * max(1,h%3);
    if (x > mcnt*9) {
        cout << -1 << endl;
        return 0;
    }
    v(string) ans(h, string(w, '0')), s1(3, string(3, '0'));
    char n1 = (char)((x/mcnt)+1+'0');
    int cmd = x % mcnt, ncnt = 0;
    const v(int) lval = { 2, 1, 1 }, rval = { 2, 1, 2 };
    int l = lval[w%3], r = rval[w%3], u = lval[h%3], d = rval[h%3];
    rep(i, 3) rep(j, 3) {
        if (i>=u&&i<=d && j>=l&&j<=r) {
            ++ncnt;
            char tc = (ncnt<=cmd)?n1:(n1-1);
            s1[i][j] = tc;
        }
    }
    rep(i, h) rep(j, w) ans[i][j] = s1[(i+1)%3][(j+1)%3];
    rep(i, h) cout << ans[i] << endl;
    return 0;
}
