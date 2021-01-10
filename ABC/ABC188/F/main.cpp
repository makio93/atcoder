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

int main(){
    ll x, y;
    cin >> x >> y;
    if (y <= x) cout << (x - y) << endl;
    else {
        ll cnt = 0;
        ll py = 0;
        while (x < y/2) {
            if (y%2 == 1) ++cnt;
            py = y;
            y /= 2;
            ++cnt;
        }
        if (y%2 == 1) {
            ll y2 = y-1, y3 = y + 1;
            --y;
            ++cnt;
            ll ecnt1 = cnt + 1, ecnt2 = cnt + 1;
            ll ecnt3 = (ll)(1e18);
            if (py%2==1) {
                ecnt2--;
                ll y4 = y3+1;
                ecnt3 = ecnt2 + 1;
                ecnt3 += llabs(x-y4/2);
            }
            cnt += llabs(y-x);
            ecnt1 += llabs(x-y2/2);
            ecnt2 += llabs(x-y3/2);
            if (y2/2 <= 0) ecnt1 = (ll)(1e18);
            if (y3/2 <= 0) ecnt2 = (ll)(1e18);
            cout << min({cnt, ecnt1, ecnt2, ecnt3}) << endl;
        }
        else {
            ll y2 = y / 2, cnt2 = cnt + 1;
            cnt += llabs(y-x);
            cnt2 += llabs(x-y2);
            if (y2 <= 0) cout << cnt << endl;
            else cout << min(cnt, cnt2) << endl;
        }
    }
    return 0;
}
