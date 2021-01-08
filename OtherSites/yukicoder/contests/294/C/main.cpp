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

const ll mod = (ll)(1e9+7);

int main(){
    int n;
    cin >> n;
    v(int) a(n);
    rep(i, n) cin >> a[i];
    v(ll) dp(n);
    dp[0] = 1;
    v(set<p2(int,ll)>) add(n);
    rep(i, n) {
        auto itr = add[i].begin();
        while (itr!=add[i].end()) {
            dp[i] = (dp[i] + itr->second) % mod;
            if (i+itr->first <= n-1) {
                add[i+itr->first].emplace(itr->first, itr->second);
            }
            ++itr;
        }
        add[i].clear();
        if (i+1<n && a[i]!=1) dp[i+1] = (dp[i+1] + dp[i]) % mod;
        if (i+a[i] <= n-1) add[i+a[i]].emplace(a[i], dp[i]);
    }
    cout << dp[n-1] << endl;
    return 0;
}
