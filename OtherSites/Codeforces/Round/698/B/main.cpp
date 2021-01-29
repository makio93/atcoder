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
        int q, d;
        cin >> q >> d;
        v(ll) a(q);
        rep(i, q) cin >> a[i];
        rep(i, q) {
            string s = to_string(a[i]);
            bool ok = (s.find((char)('0'+d)) != string::npos);
            if (ok) {
                cout << "YES" << endl;
                continue;
            }
            ll tar1 = d, tar2 = tar1;
            while (!ok && a[i]>=tar2) {
                bool fin = false;
                rep2(i2, 1, 9) {
                    if (a[i]-tar2*i2 < 0) {
                        fin = true;
                        break;
                    }
                    string ai = to_string(a[i]-tar2*i2);
                    if (ai.find((char)('0'+d)) != string::npos) {
                        ok = true;
                        break;
                    }
                }
                if (fin) break;
                tar2 *= 10;
            }
            if (ok) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}
