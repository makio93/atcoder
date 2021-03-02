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
        int n;
        v(int) cls(4);
        cin >> n;
        rep(i, 4) cin >> cls[i];
        bool ok = false;
        rep(i, 1<<4) {
            v(bool) cells(4);
            rep(j, 4) if ((i>>j)&1) cells[j] = true;
            bool ok2 = true;
            rep(j, 4) {
                if (cls[j] == n) {
                    if (!(cells[j]&&cells[(j+1)%4])) ok2 = false;
                }
                if (cls[j] == n-1) {
                    if (!cells[j] && !cells[(j+1)%4]) ok2 = false;
                }
                if (cls[j] == 1) {
                    if (cells[j] && cells[(j+1)%4]) ok2 = false;
                }
                if (cls[j] == 0) {
                    if (!(!cells[j]&&(!cells[(j+1)%4]))) ok2 = false;
                }
            }
            if (ok2) ok = true;
            if (ok) break;
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
