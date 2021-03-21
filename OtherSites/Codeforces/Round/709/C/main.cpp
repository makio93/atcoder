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
        v(int) k(m);
        v(v(int)) f(m);
        v(int) tcnt(n);
        rep(i, m) {
            cin >> k[i];
            rep(j, k[i]) {
                int fi;
                cin >> fi;
                --fi;
                f[i].pb(fi);
                tcnt[fi]++;
            }
        }
        /*
        if (n == 1) {
            rep(i, m) printf("%d%c", n, (i<m-1?' ':'\n'));
            continue;
        }
        */
        v(p2(int,p2(v(int),int))) lst(m);
        rep(i, m) {
            lst[i].first = k[i];
            lst[i].second = { f[i], i };
        }
        VSORT(lst);
        v(int) ncnt(n), ans(m);
        bool ok = true;
        rep(i, m) {
            p2(p(int),int) mval = { {(int)(INF), (int)(INF)}, -1 };
            rep(j, lst[i].first) {
                if (ncnt[lst[i].second.first[j]]+1 <= ((m+1)/2)) {
                    mval = min(mval, { { ncnt[lst[i].second.first[j]], tcnt[lst[i].second.first[j]] }, lst[i].second.first[j] });
                }
            }
            if (mval.second == -1) {
                ok = false;
                break;
            }
            ans[lst[i].second.second] = mval.second + 1;
            ncnt[mval.second]++;
        }
        if (ok) {
            rep(i, n) if (ncnt[i] > ((m+1)/2)) ok = false;
        }
        if (ok) {
            cout << "YES" << endl;
            rep(i, m) printf("%d%c", ans[i], (i<m-1?' ':'\n'));
        }
        else cout << "NO" << endl;
    }
    return 0;
}
