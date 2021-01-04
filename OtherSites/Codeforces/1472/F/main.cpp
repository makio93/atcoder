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
        vp(int) cr(m);
        rep(i, m) {
            int ri, ci;
            cin >> ri >> ci;
            ri--;
            cr[i] = { ci, ri };
        }
        VSORT(cr);
        bool ok = true;
        v(bool) state(2, true);
        int p = -1;
        rep(i, m) {
            if (i+1<m) {
                if (cr[i+1].first == cr[i].first) {
                    if (state[0] != state[1]) {
                        ok = false;
                        break;
                    }
                    while (i+1<m && cr[i+1].first==cr[i].first) {
                        p = cr[i+1].first;
                        if (i+2 < m) {
                            if (cr[i+1].first+1==cr[i+2].first) i += 2;
                            else {
                                ++i;
                                break;
                            }
                        }
                    }
                }
            }
            int d = cr[i].first - p;
            if (d > 1) {
                if (state[0]!=state[1] && (d-1)%2==1) swap(state[0], state[1]);
                p = cr[i].first - 1;
            }
            if (state[0] == state[1]) {
                p += 2;
                state[cr[i].second] = false;
                if (i+1 < m) {
                    if (cr[i+1].first == p) {
                        if (cr[i+1].second == cr[i].second) state[cr[i].second] = true;
                        else {
                            ok = false;
                            break;
                        }
                    }
                }
            }
            else {
                if (state[cr[i].second]) {
                    ++p;
                    state[0] = state[1] = true;
                }
                else {
                    ok = false;
                    break;
                }
            }
            if (p >= n) {
                ok = false;
                break;
            }
        }
        if (ok) {
            int d = (n-1)-p;
            if (d > 0) {
                if (state[0] != state[1]) ok = false;
            }
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
