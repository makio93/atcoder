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

// 本番終了後、解説AC

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        int n;
        cin >> n;
        v(int) a(n), hv(n);
        rep(i, n) cin >> a[i];
        int cnt = 0;
        rep2(i, 1, n-2) {
            bool ok = true;
            if (a[i]<a[i-1] && a[i]<a[i+1]) ok = false;
            if (a[i]>a[i-1] && a[i]>a[i+1]) ok = false;
            if (!ok) {
                ++cnt;
                hv[i]++;
            }
        }
        int msub = 0;
        rep(i, n) {
            int ncnt = 0;
            rep2(j, i-1, i+1) if (j>=0 && j<=n-1) ncnt += hv[j];
            if (i-1 >= 0) {
                int tval = a[i], tcnt = 0;
                a[i] = a[i-1];
                rep2(j, i-1, i+1) {
                    if (j<1 || j>=n-1) continue;
                    bool ok = true;
                    if (a[j]<a[j-1] && a[j]<a[j+1]) ok = false;
                    if (a[j]>a[j-1] && a[j]>a[j+1]) ok = false;
                    if (!ok) ++tcnt;
                }
                msub = max(msub, ncnt-tcnt);
                a[i] = tval;
            }
            if (i+1 <= n-1) {
                int tval = a[i], tcnt = 0;
                a[i] = a[i+1];
                rep2(j, i-1, i+1) {
                    if (j<1 || j>=n-1) continue;
                    bool ok = true;
                    if (a[j]<a[j-1] && a[j]<a[j+1]) ok = false;
                    if (a[j]>a[j-1] && a[j]>a[j+1]) ok = false;
                    if (!ok) ++tcnt;
                }
                msub = max(msub, ncnt-tcnt);
                a[i] = tval;
            }
        }
        cout << (cnt-msub) << endl;
    }
    return 0;
}
