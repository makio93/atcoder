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
        int n, k;
        cin >> n >> k;
        //int d = n - k;
        v(int) ans(k);
        rep(i, k) ans[i] = i+1;
        int cnt2 = (n-k)*(n-k+1)/2 + (n-k)*(n-k-1)/2;
        int ccnt = 0;
        do {
            int cnt = 0;
            v(int) b;
            rep(i2, k) b.pb(ans[i2]);
            rep2(i2, 1, n-k) b.pb(ans[k-i2-1]);
            rep(i2, sz(b)) {
                rep2(j2, i2+1, (sz(b)-1)) if (b[i2]>b[j2]) ++cnt;
            }
            if (cnt <= cnt2) cout << (ccnt) << endl;
            ++ccnt;
        } while (next_permutation(all(ans)));
        //rep(i, k) printf("%d%c", ans[i], (i<k-1?' ':'\n'));
    }
    return 0;
}
