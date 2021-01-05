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

// 本番終了後の自己研究

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        int n;
        cin >> n;
        int ans = 0, p = n;
        vp(int) ord;
        while (1) {
            int next = ((p + 1) / 2);
            if (next <= 2) {
                ans += p - 3;
                rep2r(i, 3, p-1) ord.eb(i, p);
                break;
            }
            ans += (p - next - 1);
            rep2r(i, next+1, p-1) ord.eb(i, p);
            int pval = p;
            while (pval > 1) {
                pval = (pval + next-1) / next;
                ++ans;
                ord.eb(p, next);
            }
            p = next;
        }
        int pval = p;
        while (pval > 1) {
            pval = (pval + 1) / 2;
            ++ans;
            ord.eb(p, 2);
        }
        cout << ans << endl;
        for (auto e : ord) {
            cout << e.first << ' ' << e.second << endl;
        }
    }
    return 0;
}
