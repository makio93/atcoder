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
        cin >> n;
        v(int) c(n), a(n), b(n);
        rep(i, n) cin >> c[i];
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];
        ll ans = 0, sum = 0;
        repr(i, n) {
            if (i == 0) {
                if (sum != 0) sum = max(sum, (ll)c[i+1]+1);
                sum += abs(a[1]-b[1]);
                ans = max(ans, sum);
                sum = 0;
            }
            else {
                if (i==n-1) sum += c[n-1] - 1;
                else if (sum == 0) {
                    sum += c[i] - 1;
                }
                else {
                    sum = max(sum, (ll)c[i+1]+1);
                    ans = max(ans, sum+abs(a[i+1]-b[i+1]));
                    sum += (ll)(c[i]-1) - abs(a[i+1]-b[i+1]);
                }
                sum += 2;
                if (a[i] == b[i]) {
                    ans = max(ans, sum);
                    sum = 0;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
