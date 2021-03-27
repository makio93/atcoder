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
    int t, pi;
    cin >> t >> pi;
    rep2(i1, 1, t) {
        v(string) qi(100);
        rep(i, 100) cin >> qi[i];
        v(double) ql(10000), sok(10000), sng(10000);
        rep(i, 10000) {
            int sum = 0;
            rep(j, 100) if (qi[j][i] == '1') ++sum;
            double rate = (double)sum / 100.0, rok = (rate+1.0) / 2.0, rng = (rate) / 2.0;
            ql[i] = log(rate/(1.0-rate));
            sok[i] = log(rok/(1.0-rok));
            sng[i] = log(rng/(1.0-rng));
        }
        p2(double, int) mval = { -1.0, -1 };
        rep(i, 100) {
            double davg = 0.0, dval = 0.0;
            rep(j, 10000) {
                if (qi[i][j] == '1') davg += sok[j];
                else davg += sng[j];
            }
            davg /= 10000.0;
            rep(j, 10000) {
                if (qi[i][j] == '1') dval += (sok[j]-davg) * (sok[j]-davg);
                else dval += (sng[j]-davg) * (sng[j]-davg);
            }
            dval /= 9999.0;
            mval = max(mval, {dval,i+1});
        }
        cout << "Case #" << i1 << ": " << mval.second << endl;
    }
    return 0;
}
