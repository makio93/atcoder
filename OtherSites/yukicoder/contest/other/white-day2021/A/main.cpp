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
    cout << "? " << 0 << ' ' << 0 << '\n';
    cout.flush();
    int d = 0;
    cin >> d;
    vp(int) a1, a2;
    rep(a, 101) rep2(b, a, 100) if (a*a+b*b==d) {
        a1.eb(a,b);
        if (a != b) a1.eb(b,a);
    }
    rep(i, sz(a1)) a1[i].second *= -1;
    VSORT(a1);
    rep(i, sz(a1)) a1[i].second *= -1;
    cout << "? " << 0 << ' ' << a1.front().second << '\n';
    cout.flush();
    cin >> d;
    p(int) pos = {0,a1.front().second};
    rep(i, sz(a1)) {
        p(int) tar = { pos.first+a1[i].first, pos.second-a1[i].second };
        if (tar.first*tar.first+tar.second*tar.second == d) {
            cout << "! " << a1[i].first << ' ' << a1[i].second << '\n';
            cout.flush();
            break;
        }
    }
    return 0;
}
