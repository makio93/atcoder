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
    rep2(i1, 1, t) {
        int n, c;
        cin >> n >> c;
        if (c<n-1 || c>(n*(n+1)/2)-1) {
            cout << "Case #" << i1 << ": " << "IMPOSSIBLE" << endl;
            continue;
        }
        int score = c - (n-1);
        v(int) l(n);
        rep(i, n) l[i] = i+1;
        repr(i, n-1) {
            if (score <= 0) break;
            int r = n-1;
            v(int) l2;
            if (score <= ((n-1)-i)) r = i + score;
            rep2r(j, i, r) l2.pb(l[j]);
            rep2(j, i, r) l[j] = l2[j-i];
            score -= sz(l2) - 1;
        }
        cout << "Case #" << i1 << ": ";
        rep(i, n) printf("%d%c", l[i], (i<n-1?' ':'\n'));
    }
    return 0;
}
