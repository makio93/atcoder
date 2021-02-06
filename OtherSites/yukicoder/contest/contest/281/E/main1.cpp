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
    if (n < 9) {
        bool ok = false;
        string ans;
        rep(i, (1<<n)) {
            string tar;
            rep(j, n) tar += (char)(((i>>j)&1)+'0');
            int mval = 0;
            rep(j, n) {
                int l = j, r = j;
                while (l>=0 && r<n) {
                    if (tar[l] == tar[r]) {
                        mval = max(mval, (r-l+1));
                        --l; ++r;
                    }
                    else break;
                }
            }
            rep(j, n-1) {
                int l = j, r = j+1;
                while (l>=0 && r<n) {
                    if(tar[l] == tar[r]) {
                        mval = max(mval, (r-l+1));
                        --l; ++r;
                    }
                    else break;
                }
            }
            if (mval == k) {
                ok = true;
                ans = tar;
                break;
            }
        }
        if (ok) cout << ans << endl;
        else cout << -1 << endl;
    }
    else {
        if (k < 4) cout << -1 << endl;
        else {
            string ans = string(k, '1');
            const string sample = "010011";
            while (sz(ans) < n) {
                if (sz(ans)+sz(sample) <= n) ans += sample;
                else ans += sample.substr(0, n-sz(ans));
            }
            cout << ans << endl;
        }
    }
    return 0;
}
