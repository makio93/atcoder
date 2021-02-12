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
    int n, k;
    cin >> n >> k;
    v(ll) a(n);
    rep(i, n) cin >> a[i];
    /*
    if (k == n) {
        ll ans = (ll)(LINF);
        if (n%2==0) {
            ll sum1 = 0, sum2 = 0, cval1 = 0, cval2 = 0;
            cval1 = (a[n/2-1]+a[n/2]) / 2, cval2 = cval1 + 1;
            rep(i, n) sum1 += llabs(cval1 - a[i]);
            rep(i, n) sum2 += llabs(cval2 - a[i]);
            ans = min(ans, min(sum1, sum2));
        }
        else {
            ll cval = a[n/2], sum = 0;
            rep(i, n) sum += llabs(cval-a[i]);
            ans = min(ans, sum);
        }
        cout << ans << endl;
    }
    */
    {
        v(ll) al(n), ar(n);
        rep(i, n) al[i] = a[i] - a[0];
        repr(i, n) ar[i] = llabs(a[i] - a[n-1]);
        reverse(all(ar));
        v(ll) suml(n+1), sumr(n+1);
        rep(i, n) suml[i+1] = suml[i] + al[i];
        rep(i, n) sumr[i+1] = sumr[i] + ar[i];
        ll pvall = suml[n] - suml[k], pvalr = sumr[n] - sumr[k];
        if (k == 0) {
            cout << (-1)*max(suml[n],sumr[n]) << endl;
            return 0;
        }
        ll mval = (ll)(LINF);
        rep2(i, 1, k) {
            ll ttar = al[i-1];
            ll nval = ((i-1)*ttar - suml[i-1]) + ((suml[k]-suml[i]) - (k-i)*ttar) - (pvall - (n-k)*ttar);
            mval = min(mval, nval);
            if (i < k) {
                ttar += (al[i] - al[i-1]) / 2;
                nval = ((i-1)*ttar - suml[i-1]) + ((suml[k]-suml[i]) - (k-i)*ttar) - (pvall - (n-k)*ttar);
                mval = min(mval, nval);
            }
        }
        rep2(i, 1, k) {
            ll ttar = ar[i-1];
            ll nval = ((i-1)*ttar - sumr[i-1]) + ((sumr[k]-sumr[i]) - (k-i)*ttar) - (pvalr - (n-k)*ttar);
            mval = min(mval, nval);
            if (i < k) {
                ttar += (ar[i] - ar[i-1]) / 2;
                nval = ((i-1)*ttar - sumr[i-1]) + ((sumr[k]-sumr[i]) - (k-i)*ttar) - (pvalr - (n-k)*ttar);
                mval = min(mval, nval);
            }
        }
        cout << mval << endl;
    }
    return 0;
}
